import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.gridspec as gridspec
import argparse
import math
from scipy import stats
import sys
import statistics 

sys.path.append('plot_lib')
import plot_aux as aux
import plot_funcs as funcs
import plot_autocal as autocal
import plot_analysis as pa
import filters as fil

args  = aux.arguments()

data1 = aux.DataStruct1(args)
t_ignore = args.freq * 20
t_ignore_fin = len(data1.time)- args.freq*32
t_ignore_fin = len(data1.time)- args.freq*12
print(t_ignore)
print(t_ignore_fin)

#version = 'one_test'
#version = 'multiple'

verbose = False
if args.plot_inv==True:
	verbose = True

########
# EXTRAER EVENTOS
########
data1.v_model_scaled[t_ignore:t_ignore_fin]  =  fil.butter_filter(data1.v_model_scaled[t_ignore:t_ignore_fin], 150, args.freq)
data1.data_in[0][t_ignore:t_ignore_fin]      =  fil.butter_filter(data1.data_in[0][t_ignore:t_ignore_fin],     150, args.freq)

fil.threshold_filter(data1.v_model_scaled[t_ignore:t_ignore_fin], 0)
fil.threshold_filter(data1.data_in[0][t_ignore:t_ignore_fin],     0)

times, model_times_ms,  events, minis, maxis = pa.periodo(data1.time[t_ignore:t_ignore_fin], data1.time_ms[t_ignore:t_ignore_fin], data1.v_model_scaled[t_ignore:t_ignore_fin], args.freq, all_events=True, plot_on=verbose)
t_model_first, t_model_last = pa.clean_all_events(times, events, plot_on=verbose)


times, living_times_ms, events, minis, maxis = pa.periodo(data1.time[t_ignore:t_ignore_fin], data1.time_ms[t_ignore:t_ignore_fin], data1.data_in[0][t_ignore:t_ignore_fin],     args.freq, all_events=True, plot_on=verbose)
t_living_first, t_living_last = pa.clean_all_events(times, events, plot_on=verbose)

fail = False

#######
# PLOT
#######
if args.plot_inv==True:
	v1 = data1.v_model_scaled[t_ignore:t_ignore_fin]
	c1 = data1.c_viva[t_ignore:t_ignore_fin]
	t1 = np.linspace(0,len(v1), len(v1))
	t1 = t1 / args.freq

	v2 = data1.data_in[0][t_ignore:t_ignore_fin]
	c2 = data1.c_model[t_ignore:t_ignore_fin]
	t2 = np.linspace(0,len(v2), len(v2))
	t2 = t2 / args.freq

	plt.figure()

	ax1 = plt.subplot(2, 1, 1)
	plt.plot(t1, v1, label='Model')
	plt.plot(t2, v2, label='Living')
	plt.plot(t_model_first,  np.linspace(2.5, 2.5, len(t_model_first)),  'o',  label="F-model" )
	plt.plot(t_model_last,   np.linspace(2.5, 2.5, len(t_model_last)),   'o',  label="L-model" )
	plt.plot(t_living_first, np.linspace(2.5, 2.5, len(t_living_first)), 'o',  label="F-living")
	plt.plot(t_living_last,  np.linspace(2.5, 2.5, len(t_living_last)),  'o',  label="L-living")

	for i in range( len(t_model_first) ):
		plt.text(t_model_first[i], 2.5, str(i))

	plt.legend(loc=1, framealpha=1.0)
	
	ax2 = plt.subplot(2, 1, 2, sharex=ax1)
	plt.plot(t1, c1, label="Current real to model", linewidth=0.8)
	plt.plot(t2, c2, label="Current model to real", linewidth=0.8)
	plt.ylabel("Current")
	plt.legend(loc=1, framealpha=1.0)

	plt.tight_layout()
	
	plt.show()

	#####################
	# INHIBICION EXTREMA
	#####################
	if  0.5*(max(v2)- min(v2)) > (max(v1)- min(v1)):
		print("Fail interaction - 1")
		fail = True
		if args.plot_inv==False:
			exit()

#######
# ORDEN DE EVENTOS
#######
try:
	print("Test")
	indexPD = 0
	#print("debug, t_model_first len="+str(t_model_first.len()))
	while t_model_first[indexPD] < t_living_first[0]:
		indexPD+=1
	size = len(t_living_first)
	if size > len(t_model_first)-indexPD:
		size = len(t_model_first)-indexPD
except:
	# Ante cualquier fallo abortamos y notificamos como no ritmo
	print("Fail interaction - 4")
	fail = True
	f_plot = open(args.name, 'a')
	# n1 n2 r_azul r_rojo s_azul s_roja rara_azul rara_roja srara_azul srara_roja
	f_plot.write(args.n1 + ' ' + args.n2 + ' 0' + ' 0' + ' 0' + ' 0' +  ' 0' + ' 0' + ' 0' + ' 0' + '\n')
	f_plot.close()
	if args.plot_inv==False:
		exit()

#######
# NO MOLA EL ORDEN DE EVENTOS
#######
aux_1 = len(t_model_first) - indexPD
aux_2 = len(t_living_first)
print('Events model vs living: ' + str(aux_1) + ' VS ' + str(aux_2) )
if abs(aux_1 - aux_2) > aux_1*0.15: #% de fallo admitido
	print("Fail interaction - 2")
	fail = True

#######
# NO HAY SPIKES
#######
for i in range(20):
	if t_model_first[i]==t_model_last[i]:
		print("Fail interaction - 3")
		#fail = True
		break

#######
# ALGUN FAIL +
#######
if fail == True:
	f_plot = open(args.name, 'a')
	# n1 n2 r_azul r_rojo s_azul s_roja rara_azul rara_roja srara_azul srara_roja
	f_plot.write(args.n1 + ' ' + args.n2 + ' 0' + ' 0' + ' 0' + ' 0' +  ' 0' + ' 0' + ' 0' + ' 0' + '\n')
	f_plot.close()
	if args.plot_inv==False:
		exit()

#######
# INTERVALOS
#######
periodoLP      =  []
durationModel  =  []
PDtoLP         =  []
PDtoLP_raro    =  []
delay          =  []
delay_raro     =  []

ml = 0 # model less
for i in range(size-1):

	# El modelo no disparo
	if t_living_first[i] < t_model_first[i-ml]:
		# El modelo no disparo, no hacemos nada
		ml+=1

	else:
		# Calculo intervalos
		periodoLP_i      =  t_living_first [i+1]  - t_living_first [i]
		durationModel_i  =  t_model_last   [i-ml] - t_model_first  [i-ml]

		PDtoLP_i  =  t_model_first  [i+indexPD-ml] - t_living_first [i]
		delay_i   =  t_model_first  [i+indexPD-ml] - t_living_last  [i]  

		# Comprobar. Evita ruidos intermedios.
		# Testeado que no afecta a la siguiente rafaga
		# Ni indica desplazamientos en los indices 
		# Solo indica una rafaga con ruido
		if (periodoLP_i < PDtoLP_i):
			print("Revisar numero " + str(i))

		else:
			# Guardar
			periodoLP.append     ( periodoLP_i     )
			durationModel.append ( durationModel_i )

			PDtoLP.append        ( PDtoLP_i   ) 
			delay.append         ( delay_i    ) 


			# Raro
			PDtoLP_raro.append   ( t_living_first [i+1] - t_model_first  [i+indexPD-ml] )
			delay_raro.append    ( t_living_first [i+1] - t_model_last   [i+indexPD-ml] )

print("Model jump = " + str(ml))

#######
# R2
#######
print('----> ' + args.n1 + ' and ' + args.n2 + ' <----')

slope, intercept, r_value, p_value, std_err = stats.linregress(periodoLP, PDtoLP)
print( "Blue:      R2={:.2f}".format(r_value **2*100) + "%    m={:.3f}".format(slope ) )
slope2, intercept2, r_value2, p_value2, std_err2 = stats.linregress(periodoLP, delay)
print( "Red:       R2={:.2f}".format(r_value2**2*100) + "%    m={:.3f}".format(slope2) )

slope3, intercept3, r_value3, p_value3, std_err3 = stats.linregress(periodoLP, PDtoLP_raro)
#print( "Blue+1:    R2={:.2f}".format(r_value3**2*100) + "%    m={:.3f}".format(slope3 ) )
slope4, intercept4, r_value4, p_value4, std_err4 = stats.linregress(periodoLP, delay_raro)
#print( "Red+1:     R2={:.2f}".format(r_value4**2*100) + "%    m={:.3f}".format(slope4) )


mean_periodoLP = statistics.mean(periodoLP)
print("Media = " + str(mean_periodoLP) )

stdev_periodoLP = statistics.stdev(periodoLP)
print("Desviacion estandar = " + str(stdev_periodoLP) )

conf_int = stats.norm.interval(0.99, loc=mean_periodoLP, scale=stdev_periodoLP)
print("Intervalo 99% del periodo = ")
print(conf_int)

for i in range(len(periodoLP)):
	if periodoLP[i]<conf_int[0] or periodoLP[i]>conf_int[1]:
		# Crear listas sin
		pppppp=1

#######
# PLOT
#######
if args.plot_inv==True:
	plt.plot(periodoLP, intercept + slope*np.asarray(periodoLP), alpha=0.5)
	label = '1stLP to 1stDP    R2={:.2f}'.format(r_value **2*100) + '%    m={:.3f}'.format(slope )
	plt.scatter(periodoLP, PDtoLP, label=label, c=np.linspace(0, len(periodoLP), len(periodoLP)), s=5, cmap=plt.get_cmap('Blues'))
	plt.colorbar()

	for i in range(len(periodoLP)):
		plt.text(periodoLP[i], PDtoLP[i], str(i))
	'''
	plt.plot(periodoLP, intercept2 + slope2*np.asarray(periodoLP), alpha=0.5)
	label = 'With delay          R2={:.2f}'.format(r_value2 **2*100) + '%    m={:.3f}'.format(slope2 )
	plt.scatter(periodoLP, delay, label=label, c=np.linspace(0, len(periodoLP), len(periodoLP)), s=5, cmap=plt.get_cmap('Reds'))
	plt.colorbar()
	'''
	'''
	plt.scatter(periodoLP, durationModel, c=np.linspace(0, len(periodoLP), len(periodoLP)), s=5, cmap=plt.get_cmap('Greens'))
	plt.colorbar()
	plt.xlabel("Period")
	plt.ylabel("")
	'''

	plt.title("Invariant")
	plt.legend(loc=1, framealpha=1.0)
	#plt.tight_layout()
	plt.show()

	############

	'''
	plt.plot(periodoLP, intercept3 + slope3*np.asarray(periodoLP), alpha=0.5)
	label = '1stLP to 1stDP    R2={:.2f}'.format(r_value3 **2*100) + '%    m={:.3f}'.format(slope3 )
	plt.scatter(periodoLP, PDtoLP_raro, label=label, c=np.linspace(0, len(periodoLP), len(periodoLP)), s=5, cmap=plt.get_cmap('Blues'))
	plt.colorbar()

	plt.plot(periodoLP, intercept4 + slope4*np.asarray(periodoLP), alpha=0.5)
	label = 'With delay          R2={:.2f}'.format(r_value4 **2*100) + '%    m={:.3f}'.format(slope4 )
	plt.scatter(periodoLP, delay_raro, label=label, c=np.linspace(0, len(periodoLP), len(periodoLP)), s=5, cmap=plt.get_cmap('Reds'))
	plt.colorbar()

	plt.scatter(periodoLP, durationModel, c=np.linspace(0, len(periodoLP), len(periodoLP)), s=5, cmap=plt.get_cmap('Greens'))
	plt.colorbar()

	plt.xlabel("Period")
	plt.ylabel("")
	
	plt.title("Invariant")
	plt.legend(loc=1, framealpha=1.0)
	plt.tight_layout()
	plt.show()
	'''

else:
	f_plot = open(args.name, 'a')
	# n1 n2 r_azul r_rojo s_azul s_roja rara_azul rara_roja srara_azul srara_roja
	f_plot.write(args.n1 + ' ' + args.n2 + ' {:.5f}'.format(r_value**2*100) + ' {:.5f}'.format(r_value2**2*100) + ' {:.5f}'.format(slope) + ' {:.5f}'.format(slope2) +  ' {:.5f}'.format(r_value3**2*100) + ' {:.5f}'.format(r_value4**2*100) + ' {:.5f}'.format(slope3) + ' {:.5f}'.format(slope4) + '\n')
	f_plot.close()





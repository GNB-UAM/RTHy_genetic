# Crear XML
def create_xml(var_a, var_b, exp_code):

	# Senal 1
	#entrada    = 'data_in/2019y_3m_14d/17h_25m_23s_data.txt'

	# Senal 2
	#entrada    = 'data_in/2019y_6m_6d/16h_57m_39s_data.txt'

	# senal 3
	#entrada    =  'data_in/12-Nov-2019/16h45m10s-12-Nov-2019.txt'
	#entrada    =  'data_in/17-Dec-2019/17h39m04s-17-Dec-2019.txt'
	#entrada    =  'data_in/10-Sep-2019/16h42m53s-10-Sep-2019.txt'
	#entrada    =  'data_in/22-Oct-2019/16h17m41s-22-Oct-2019.txt'	

	salida     = '/'+exp_code+'_'+str(var_a)+'_'+str(var_b)#+something

	xml = 'xml_in/genetico/'
	name = xml+str(var_a)+'_'+str(var_b)+'.xml'
	f = open(name, 'w', newline='\n')
	# XML struct
	f.write('<clamp>\n\n')

	# IZHIKEVICH
	
	f.write('	<neuron type="1">\n')
	f.write('		<vars>\n')
	f.write('			<v val="30.24"/>\n')
	f.write('			<u val="-5.5"/>\n')
	f.write('		</vars>\n')
	f.write('		<params>\n')
	f.write('			<a val="0.02"/>\n')	
	f.write('			<b val="0.2"/>\n')	
	f.write('			<c val="-50.0"/>\n')	
	f.write('			<d val="2.0"/>\n')	
	f.write('			<i val="10.0"/>\n')	
	f.write('			<method val="3"/>\n')	
	f.write('		</params>\n')
	f.write('	</neuron>\n\n')
	

	# K-K standar
	'''
	f.write('	<neuron type="6">\n')
	f.write('		<vars>\n')
	f.write('			<V val="-55.0"/>\n')
	f.write('		</vars>\n')
	f.write('		<params>\n')
	f.write('			<i         val="0.0"/>\n')
	f.write('			<Cm        val="0.02"/>\n')

	f.write('			<g_na      val="0.0231"/>\n')
	f.write('			<g_k       val="0.25"/>\n')
	f.write('			<g_b       val="0.165"/>\n')
	f.write('			<g_na_v    val="0.11"/>\n')
	f.write('			<V_k       val="-70.0"/>\n')
	f.write('			<V_b       val="-58.0"/>\n')
	f.write('			<V_na      val="40.0"/>\n')
		
	f.write('			<g_na_ttx  val="400.0"/>\n')
	f.write('			<g_ca      val="1.5"/>\n')
	f.write('			<k_beta    val="15000.0"/>\n')
	f.write('			<g_k_tea   val="10.0"/>\n')
	f.write('			<V_ca      val="150.0"/>\n')
	f.write('			<beta      val="0.00004"/>\n')
	f.write('			<g_ca_ca   val="0.02"/>\n')
	f.write('			<k_s       val="50.0"/>\n')
	f.write('			<rho       val="0.002"/>\n')	
		
	f.write('			<method    val="3"/>\n')
	f.write('		</params>\n')
	f.write('	</neuron>\n\n')
	'''

	# K-K chaotic
	'''
	f.write('	<neuron type="6">\n')
	f.write('		<vars>\n')
	f.write('			<V val="-55.0"/>\n')
	f.write('		</vars>\n')
	f.write('		<params>\n')
	f.write('			<i         val="0.0"/>\n')
	f.write('			<Cm        val="0.02"/>\n')
	f.write('			<g_na      val="0.02"/>\n')
	f.write('			<g_k       val="0.25"/>\n')
	f.write('			<g_b       val="0.18"/>\n')
	f.write('			<g_na_v    val="0.13"/>\n')
	f.write('			<V_k       val="-70.0"/>\n')
	f.write('			<V_b       val="-58.0"/>\n')
	f.write('			<V_na      val="40.0"/>\n')
		
	f.write('			<g_na_ttx  val="400.0"/>\n')
	f.write('			<g_ca      val="1.0"/>\n')
	f.write('			<k_beta    val="15000.0"/>\n')
	f.write('			<g_k_tea   val="10.0"/>\n')
	f.write('			<V_ca      val="150.0"/>\n')
	f.write('			<beta      val="0.00004"/>\n')
	f.write('			<g_ca_ca   val="0.01"/>\n')
	f.write('			<k_s       val="50.0"/>\n')
	f.write('			<rho       val="0.002"/>\n')	
		
	f.write('			<method    val="3"/>\n')
	f.write('		</params>\n')
	f.write('	</neuron>\n\n')
	'''
		
	# G-H
	'''
	f.write('	<neuron type="4">\n')
	f.write('		<vars>\n')
	f.write('			<v val="30.24"/>\n')
	f.write('		</vars>\n')
	f.write('		<params>\n')
	f.write('			<gca val="4.4"/>\n')
	f.write('			<eca val="120"/>\n')
	f.write('			<vthca val="-1.2"/>\n')
	f.write('			<kca val="0.11"/>\n')

	f.write('			<gk val="9"/>\n')
	f.write('			<ek val="-80"/>\n')
	f.write('			<vthk val="2.0"/>\n')
	f.write('			<kk val="0.2"/>\n')

	f.write('			<gks val="0.25"/>\n')
	f.write('			<vthks val="-27"/>\n')
	f.write('			<kks val="0.8"/>\n')
	
	f.write('			<gl val="2.0"/>\n')
	f.write('			<el val="-60"/>\n')

	f.write('			<c val="1.2"/>\n')
	f.write('			<epsilon val="4.9"/>\n')
	f.write('			<delta val="0.052"/>\n')
	f.write('			<i val="35.6"/>\n')

	f.write('			<method val="3"/>\n')
	f.write('		</params>\n')
	f.write('	</neuron>\n')
       '''

	# H-R
	'''
	f.write('	<neuron type="2">\n')
	f.write('		<vars>\n')
	f.write('			<x val="-0.712841"/>\n')
	f.write('			<y val="-1.936880"/>\n')
	f.write('			<z val="3.165680"/>\n')
	f.write('		</vars>\n')
	f.write('		<params>\n')
	f.write('			<r val="0.0021"/>\n')
	f.write('			<s val="4.0"/>\n')
	f.write('			<i val="3.0"/>\n')

	f.write('		<method val="3"/>\n')
	f.write('		</params>\n')
	f.write('	</neuron>\n')
	'''

	# H-R chaotic
	'''
	f.write('	<neuron type="2">\n')
	f.write('		<vars>\n')
	f.write('			<x val="-0.712841"/>\n')
	f.write('			<y val="-1.936880"/>\n')
	f.write('			<z val="3.165680"/>\n')
	f.write('		</vars>\n')
	f.write('		<params>\n')
	f.write('			<r val="0.0021"/>\n')
	f.write('			<s val="4.0"/>\n')
	f.write('			<i val="3.281"/>\n')

	f.write('		<method val="3"/>\n')
	f.write('		</params>\n')
	f.write('	</neuron>\n')
	'''




	# SYNAPSE TO MODEL

	f.write('	<synapse_ltom type="2">\n')
	f.write('		<g_slow val="0"/>\n')
	f.write('		<vth_slow val="40"/>\n')
	f.write('		<s_slow val="1.0"/>\n')
	f.write('		<k1_slow val="1.0"/>\n')
	f.write('		<k2_slow val="0.03"/>\n\n')

	# ~~~~~~~~
	f.write('		<g_fast val="'+str(var_b)+'"/>\n')
	#f.write('		<g_fast val="0.6"/>\n')

	f.write('		<vth_fast val="'+str(var_a)+'"/>\n')
	#f.write('		<vth_fast val="32.0"/>\n')

	#f.write('		<s_fast val="'+str(var_b)+'"/>\n')
	f.write('		<s_fast val="5.0"/>\n')
	# ~~~~~~~~

	f.write('	</synapse_ltom>\n\n')




	# SYNAPSE TO LIVING

	f.write('	<synapse_mtol type="2">\n')
	f.write('		<g_slow val="'+str(var_b)+'"/>\n')
	f.write('		<vth_slow val="35"/>\n')
	f.write('		<s_slow val="1.0"/>\n')
	f.write('		<k1_slow val="1.0"/>\n')
	f.write('		<k2_slow val="0.03"/>\n\n')

	f.write('		<g_fast val="0.0"/>\n')
	f.write('		<vth_fast val="0.0"/>\n')
	f.write('		<s_fast val="0.0"/>\n')
	f.write('	</synapse_mtol>\n\n')


	# MORE

	f.write('	<calib type="0"> </calib>\n\n')

	f.write('	<freq val="10000"/>\n\n')

	f.write('	<times>\n')
	f.write('		<before val="10"/>\n')
	f.write('		<duration val="60"/>\n')
	f.write('		<after val="10"/>\n')
	f.write('		<observation val="10"/>\n')
	f.write('	</times>\n\n')

		
	f.write('	<output_channels val="0"/>\n')
	f.write('	<input_channels val="0"/>\n')
	f.write('	<input_factor val="100"/>\n')
	f.write('	<output_factor val="10"/>\n')
	f.write('	<imp val="0"/>\n')
	f.write('	<drift val="1"/>\n')
	f.write('	<sec_per_burst val="-1"/>\n\n') #-1 senal 1
	#f.write('	<sec_per_burst val="2.8"/>\n\n') #-1 senal 1

	#f.write('	<file val="' +entrada+ '"/>\n')
	f.write('	<file_out val="' +salida+ '"/>\n\n')

	f.write('</clamp>\n')
	f.close()	

	return name, salida
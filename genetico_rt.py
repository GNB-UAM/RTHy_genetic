import random as rd
import genetico_xml as xml
from datetime import date
import os
import argparse

# Argumentos
parser = argparse.ArgumentParser()
parser.add_argument('--experiment_code', required=True)
args = vars(parser.parse_args())

# Clase individuo
class Individuo:
	def __init__(self):
		self.var_a = rd.uniform(20, 60)
		self.var_b = rd.uniform(0, 10) * 0.05
		self.r2 = 0
		self.elite = False
		self.salida = 'None'

# Create initial population
population_n = 4
gen_n = 3
population = []
population_new = []
for i in range(population_n):
	population.append(Individuo())
	population_new.append(Individuo())

file_info = open( str(args['experiment_code']) + "_file_info.txt", "w")

for gen_i in range(gen_n):
	
	# Fitness function (execute simulation and save R2)
	for individuo in population:

		if individuo.elite==True:
			print("\n========\n")
			print(individuo.name)
			print("Already tested individual")

		if individuo.elite==False:

			name, salida = xml.create_xml(individuo.var_a, individuo.var_b, str(args['experiment_code']))
			today = date.today().strftime("%Yy_%-mm_%-dd")
			salida = 'data/' + str(today) + salida + '_data.txt'

			individuo.name = name
			individuo.salida = salida

			print("\n========\n")
			print(individuo.name)

			os.system("./RTHybrid -xml "+name)
			os.system("export PATH='/home/gnb/anaconda3/bin:$PATH' && " + "python invariante.py -f "+salida+" -n1 "+str(individuo.var_a)+" -n2 "+str(individuo.var_b)+" -n "+str(args['experiment_code'])+"_result.txt")
			
			with open( str(args['experiment_code']) + '_result.txt', 'r') as f:
				last_line = f.read().splitlines()[-1]
				last_line = last_line.split(' ')
				individuo.r2 = float(last_line[2])

	# Selection and elite
	file_info.write("GENERACION "+str(gen_i)+"\n")
	print("\n ======= GENERACION "+str(gen_i)+" =======")

	population = sorted(population, key=lambda x: x.r2, reverse=True)

	for individuo in population:
		print(str(individuo.r2))
		print(str("a = " + str(individuo.var_a)))
		print(str("b = " + str(individuo.var_b)))
		file_info.write(str(individuo.r2)+"\n")
		file_info.write(str("a = " + str(individuo.var_a) + "\n"))
		file_info.write(str("b = " + str(individuo.var_b) + "\n"))
		individuo.elite = False

	file_info.write("\n")
	print("")

    # Elite
	population_new[0] = population[0]
	population_new[0].elite = True
	#population_new[population_n-1] = Individuo()
	#population_new[population_n-2] = Individuo()
	#population_new[population_n-3] = Individuo()

	# Elite and discard zero r2
	index_descart = population_n-1
	for i in range(population_n):
		if population[i].r2 == 0:
			index_descart = i
			break
	for i in range(population_n):
		if population[i].r2 == 0:
			population_new[i] = Individuo()

	# Crossover
	for i in range(population_n-1):
		# Crossover except elite
		gen_a = population[rd.randint(0, index_descart)].var_a
		gen_b = population[rd.randint(0, index_descart)].var_b
		population_new[i+1].var_a = gen_a
		population_new[i+1].var_b = gen_b

	# Mutation
	for i in range(population_n-1):
		randnum = rd.randrange(-100, 100)/100
		randnum = population_new[i+1].var_a + randnum
		if randnum > 0:
			population_new[i+1].var_a = randnum
		else:
			population_new[i+1].var_a = randnum + 1

		randnum = rd.randrange(-100, 100)/100
		randnum = population_new[i+1].var_b + randnum
		if randnum > 0:
			population_new[i+1].var_b = randnum
		else:
			population_new[i+1].var_b = randnum + 1

	population = population_new
	
	
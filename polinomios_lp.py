from numpy.polynomial import polynomial as pol
import sys
import os

print "OPERACIONES CON POLINOMIOS"
class Comandos():	
	def ayuda(self):
		print ">>"
		print("valuar: Valuar un polinomio en un punto dado")
		print("sumar: Suma dos polinomios")
		print("restar: Resta dos polinomios")
		print("igualdad: Compara dos polinomios")
		print("opuesto: Obtiene el polinomio opuesto")
		print("multiplicar: Multiplica dos polinomios")
		print("limpiar: Limpia la consola")
		print("salir: Cerrar la consola")

	def valuar(self):
		coeficientes = obtenerPolinomio()			
		valor = input("Valuar en x=")
		print "P(x)"
		imprimirPolinomio(coeficientes) 		
   		polinomio_valuado = pol.polyval(valor,coeficientes)
		print ("\nP(%.2f) = %d" %(valor,polinomio_valuado))
		
	def sumar(self):
		print "Polinomio 1"
		coeficientes1 = obtenerPolinomio()
		print"Polinomio 2"
		coeficientes2 = obtenerPolinomio()	
		polinomio_suma = pol.polyadd(coeficientes1, coeficientes2)
		print "P_suma(x) = "
		imprimirPolinomio(polinomio_suma)

	def igualdad(self):
		print "Polinomio 1"
		coeficientes1 = obtenerPolinomio()
		print"Polinomio 2"
		coeficientes2 = obtenerPolinomio()

		if coeficientes1 == coeficientes2:
			print "Los polinomios son iguales"
		else: 
			print "Los polinomios no son iguales"
		print "P1(x) = "			
		imprimirPolinomio(coeficientes1)
		print "P2(x) = "
		imprimirPolinomio(coeficientes2)
	
	def opuesto(self):
		coeficientes = obtenerPolinomio()
		print "P_original(x) = "
		imprimirPolinomio(coeficientes)
		for i in range(len(coeficientes)):
			coeficientes[i] = coeficientes[i]*-1
		print "P_opuesto(x) = "
		imprimirPolinomio(coeficientes)

	def restar(self):
		print "Polinomio 1"
		coeficientes1 = obtenerPolinomio()
		print"Polinomio 2"
		coeficientes2 = obtenerPolinomio()
		polinomio_resta = pol.polysub(coeficientes1, coeficientes2)
		print "P_resta(x) = "
		imprimirPolinomio(polinomio_resta)
	
	def multiplicar(self):
		print "Polinomio 1"
		coeficientes1 = obtenerPolinomio()
		print"Polinomio 2"
		coeficientes2 = obtenerPolinomio()
		polinomio_multiplicacion = pol.polymul(coeficientes1, coeficientes2)
		print "P_producto(x) = "
		imprimirPolinomio(polinomio_multiplicacion)


	def salir(self):
		print " "

	def limpiar(self):
		os.system('cls')

def imprimirPolinomio(coeficientes):
	for i in range(len(coeficientes)):
		sys.stdout.write("%+.2fx^%d "%(coeficientes[i],i)) #Impresion en una sola linea
   		sys.stdout.flush()		
   	print " "

def obtenerPolinomio():
	grado = input("Grado del polinomio: ")
	coeficientes = [0]*(grado+1)
	for i in range(0,grado+1):	
		coeficientes[i] = input("Coeficiente %d: " %i)
	return coeficientes

#Imitacion de una consola de comandos
#Los comandos con sus respectivos metodos se almacenan en un directorio para utilizarlo como un switch
def shell():
	print"\n"
	print ">>"
	print "Teclear ayuda para ver lista de comandos"
	cmd = Comandos()
	comando = "entrar" #PARA ENTRAR AL CICLO
	while(comando != "salir"):
		comandos = {'ayuda': cmd.ayuda,'valuar':cmd.valuar,'sumar':cmd.sumar,'restar':cmd.restar,'igualdad':cmd.igualdad,'opuesto':cmd.opuesto,'multiplicar':cmd.multiplicar,'limpiar': cmd.limpiar, 'salir': cmd.salir }
		comando = raw_input('>>')
		
		try:
			comandos[comando]()
		except:
			print (" %s no se reconoce como un comando. Teclea 'ayuda' para ver lista de comandos" %comando)

shell()

from sympy import symbols, Eq, solve
import os
encendido = "Y"
while not encendido == "N":
    print("\n\t\t\t\tCIRCUITO N6\n")
    print("\t\t        ┌────────ICT─►───────────┐")
    print("\t\t        │                      foco")
    print("\t\t        │                        |")
    print("\t\t  ┌─────┤                ┌───────┤")
    print("\t\t  │     |           IB1  ↓IC1    |")
    print("\t\t  |     └─Rv──R(10k)─►──|T1      |")
    print("\t\t  V(12) (470k)        IE1↓IB2    ↓IC2")
    print("\t\t  │                      └─────►|T2") 
    print("\t\t  │                              ↓IE2")  
    print("\t\t  └──────────────────────────────┘\n")
    while True:
        opcion = input("\nElija una opcion:\n\tA)Calculo Factor Beta\n\tB)Corrientes\n\t\tOpcion: ").upper()
        if opcion == "A":
            IB, IE, BT = symbols("IB IE BT")
            print ("Ingrese el valor de la Resistencia variable")
            Rv = int(input())
            print ("Ingrese el valor de la corriente IC")
            IC = float(input())
            V=12
            R=10000
            Ve=0.7
            ecu_1 = Eq((Rv+R)*IB+IB*BT,V-2*Ve)
            ecu_2 = Eq(IE-BT,IC)
            ecu_3 = Eq(BT*IB,IC)

            solucion = solve([ecu_1, ecu_2, ecu_3], [IB, IE, BT])

            print("la Ganancia de Beta:",solucion)
            os.system("pause")
            break
        if opcion == "B":
            print ("\tSiendo: V(voltaje), Rv(Resistor variable))\n")
            print ("\t\tB1(factor Beta 1), B2(Factor Beta 2))\n")
            print ("Ingrese V, Rv, B1 y B2 separados por espacios\n")
            V, Rv, B1, B2 = map(int, input().split())
            R=10000
    #corriente en la base
            IB1=round((V-1.41)/(Rv+R+(B1*B2)),7)
    #corriente en el colector
            IC1=round(B1*IB1,7)
    #corriente en el emisor
            IE1=round(IC1+IB1,7)
            IB2=IE1
            IC2=round(B2*IB2,7)
            IE2=round(IC2+IB2,7)
            ICT=round(IC1+IC2,7)
            print("Para el Transistor 1:\n")
            print("\t\t          ↓IC1    ")
            print("\t\t        ./        ")
            print("\t\t  ─IB1─►|T1      ")
            print("\t\t        '\        ")
            print("\t\t          ↓IE1    \n")
            print("la Corriente en la base es:\n", IB1)
            print("la Corriente en el colector es:\n", IC1)
            print("la Corriente en el emisor es:\n", IE1)
            print("Para el Transistor 2:\n")
            print("\t\t          ↓IC2    ")
            print("\t\t        ./        ")
            print("\t\t  ─IB2─►|T2      ")
            print("\t\t        '\        ")
            print("\t\t          ↓IE2    \n")
            print("la Corriente en la base es:\n", IB2)
            print("la Corriente en el colector es:\n", IC2)
            print("la Corriente en el emisor es:\n", IE2)
            print("La corriente en el FOCO es:\n",ICT)
            print("La gananacia total es:\n",B1*B2)
            encendido = input("\nSi desea seguir en el programa digite 'Y' caso contrario 'N':   ").upper()
            print("\n\n\tGracias, hasta luego!!")
            break

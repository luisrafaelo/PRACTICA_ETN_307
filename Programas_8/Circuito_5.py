from sympy import symbols, Eq, solve
encendido = "Y"
while not encendido == "N":
    print("\n\t\t\t\tCIRCUITO N5\n")
    print("\t\t           I5       +Vo-")
    print("\t\t         ┌──►────────R1───────────┐")
    print("\t\t         |                        |")
    print("\t\t     I1  │ I7      +   I6         |I4")
    print("\t\t  ┌───►──┼─►─Vd(4Io)──┬◄──Id(2Vo)─┼◄─R5──┐")
    print("\t\t  │      ↓ I2         ↓ I3        ↓Io   +|")
    print("\t\t I↑      R2          R3          R4      V")
    print("\t\t  │      |            |           |      |")
    print("\t\t  └──────┴────────────┴───────────┴──────┘")
    
    while True:
        opcion = input("\nElija una opcion:\n\tA)Valores predeterminados\n\tB)Nuevos Valores\n\t\tOpcion: ").upper()
        if opcion == "A":
            print("\n\t\tLos valores del circuito tiene los siguientes valores:")
            print("\n\tR1 = 1 ohm\tR2 = 4 ohm\tR3 = 1 ohm")
            print("\tR4 = 4 ohm\tR5 = 2 ohm")
            print("\tV = 10 voltios\tVd = 2(Io) voltios\tI = 1 amperios\tId = 2(Vo) amperios\n")
            R1 = 1; R2 = 4; R3 = 1; R4 = 4; R5 = 2; V = 10; Vd = 4; I = 1; Id = 2
            V1, V2, V3, =symbols("V1 V2 V3 ")
            ecu_1 = Eq(((1/R2)+(1/R1)-Id)*V1 + (1/R3)*V2 + (Id-(1/R1))*V3,I)
            ecu_2 = Eq((Id-(1/R1))*V1 + (0)*V2 + ((1/R1)+(1/R4)-Id)*V3,V/R5)
            ecu_3 = Eq((1)*V1 + (-1)*V2 + (Vd/R4)*V3,0)

            solucion = solve([ecu_1, ecu_2, ecu_3], [V1, V2, V3])

            a = solucion[V1]
            b = solucion[V2]
            c = solucion[V3]
    #calculamos las corrientes
            Io = round(c/R4,5)
            I1 = round(I,5)
            I2 = round(a/R2,5)
            I3 = round(b/R3,5)
            I4 = round(V/R5,5)
            I5 = round((a-c)/R1,5)
            I6 = round(2*(c-a),5)
            I7 = round((I-(a/R2)-(a-c)/R1),5)

            print("las Corrientes son: ")
            print("\nIo:",Io)
            print("\nI1:",I1)
            print("\nI2:",I2)
            print("\nI3:",I3)
            print("\nI4:",I4)
            print("\nI5:",I5)
            print("\nI6:",I6)
            print("\nI7:",I7)
            break
        if opcion == "B":
            print("Ingrese R1, R2 ,R3, R4, R5 separado por espacios:\n")
            R1, R2, R3, R4, R5 = map(int, input().split())
            print ("Ingrese la fuentes  V, Vd, I, Id separados por espacios\n")
            V, Vd, I, Id = map(int, input().split())
            
            V1, V2, V3, =symbols("V1 V2 V3 ")
            ecu_1 = Eq(((1/R2)+(1/R1)-Id)*V1 + (1/R3)*V2 + (Id-(1/R1))*V3,I)
            ecu_2 = Eq((Id-(1/R1))*V1 + (0)*V2 + ((1/R1)+(1/R4)-Id)*V3,V/R5)
            ecu_3 = Eq((1)*V1 + (-1)*V2 + (Vd/R4)*V3,0)

            solucion = solve([ecu_1, ecu_2, ecu_3], [V1, V2, V3])

            a = solucion[V1]
            b = solucion[V2]
            c = solucion[V3]
    #calculamos las corrientes
            Io = round(c/R4,5)
            I1 = round(I,5)
            I2 = round(a/R2,5)
            I3 = round(b/R3,5)
            I4 = round(V/R5,5)
            I5 = round((a-c)/R1,5)
            I6 = round(2*(c-a),5)
            I7 = round((I-(a/R2)-(a-c)/R1),5)

            print("las Corrientes son: ")
            print("\nIo:",Io)
            print("\nI1:",I1)
            print("\nI2:",I2)
            print("\nI3:",I3)
            print("\nI4:",I4)
            print("\nI5:",I5)
            print("\nI6:",I6)
            print("\nI7:",I7)
    
            encendido = input("\nSi desea seguir en el programa digite 'Y' caso contrario 'N':   ").upper()
            print("\n\n\tGracias, hasta luego!!")
            break

from sympy import *


def verificador_numerico(orden, lim_izquierdo, lim_derecho):
    while True:
        try:
            x = float(input(f"\n\tIngrese {orden}: "))
            if not (lim_izquierdo < x < lim_derecho):
                print(f"\tEl valor no entra en los Limites {lim_izquierdo} < Numero < {lim_derecho}")
                continue
            return x
        except:
            print("\tSolo valores decimales son permitidos (para un entero sera ' .00 ')")
            continue


encendido = "Y"
while not encendido == "N":
    print("\t\t\tC I R C U I T O  NRO.  2")
    print("\n\t\tR = Resistencia       V = Fuente de voltaje       I = Fuente de Corriente")
    # Codigos de Alt + ║186  ═205   ╩202  ╦203  ╬206  ╔201  ╗187  ╝188  ╚200  ╣185  ╠204
    # Codigos de Alt + │179  ─196  ┼197  ├195  ┤180  ┌218  ┐191  ┘217  └192  ┴193  ┬194
    # Codigos de Alt + ↑24   ↓25    196─►16     17◄─196
    print("\t\t ┌──────────────────────R(1)─────────────┐")
    print("\t\t │   8*IR─►                              │")
    print("\t\t ├────I(1)───────────────────────────────┤")
    print("\t\t │                          ◄─    ◄─IR   │")
    print("\t\t ├───R(2)───┬──────────┬───I(2)───R(3)───┤")
    print("\t\t │          │          │                 │")
    print("\t\t │         R(4)        │                 │")
    print("\t\tV(1)↑       │         R(5)               │")
    print("\t\t │2*VR     V(2)↑       │                 │")
    print("\t\t │          │          │                 │")
    print("\t\t │    ─►    │   IR─►   │    ◄─           │")
    print("\t\t ├───V(3)───┴───R(6)───┴───V(4)──────────┤")
    print("\t\t │                              ─►       │")
    print("\t\t └────────────R(7)─────────────V(5)──────┘")

    R1 = 6
    R2 = 7
    R3 = 5
    R4 = 4
    R5 = 3
    R6 = 2
    R7 = 1
    I2 = 9
    V2 = 2
    V3 = 6
    V4 = 3
    V5 = 4

    while True:
        opcion = input("\n\t\tDesea usar:   A)Valores predeterminados      B)Nuevos Valores\n\t\tOpcion: ").upper()
        if opcion == "A":
            print("\n\t\tPor defecto el circuito tiene los siguientes valores:")
            print("\n\t\tR(1) = 6 ohmios      R(2) = 7 ohmios      R(3) = 5 ohmios")
            print("\t\tR(4) = 4 ohmios      R(5) = 3 ohmios      R(6) = 2 ohmios")
            print("\t\tR(7) = 1 ohmio      I(2) = 9 amperios       V(2) = 2 voltios")
            print("\t\tV(3) = 6 voltios       V(4) = 3 voltios       V(5) = 4 voltios")
            # R(1) es a     R(2) es b     R(3) es c     R(4) es d     R(5) es e
            # R(6) es f     V(1) es g     I(1) es h     I(2) es i
            break
        if opcion == "B":
            R1 = verificador_numerico("R(1)", -10000, 10000)
            R2 = verificador_numerico("R(2)", -10000, 10000)
            R3 = verificador_numerico("R(3)", -10000, 10000)
            R4 = verificador_numerico("R(4)", -10000, 10000)
            R5 = verificador_numerico("R(5)", -10000, 10000)
            R6 = verificador_numerico("R(6)", -10000, 10000)
            R7 = verificador_numerico("R(7)", -10000, 10000)
            I2 = verificador_numerico("I(2)", -10000, 10000)
            V2 = verificador_numerico("V(2)", -10000, 10000)
            V3 = verificador_numerico("V(3)", -10000, 10000)
            V4 = verificador_numerico("V(4)", -10000, 10000)
            V5 = verificador_numerico("V(5)", -10000, 10000)
            break
        else:
            print("\t\tNo selecciono alguna de las opciones anteriores, vuelva a intentarlo")
            continue
    print("\t\tLo que pide el problema es la corriente IR y el voltaje VR")
    print("\t\tUsando el metodo de nodos, se analizara el circuito por nodos (N):")
    print("\t\tN1○──────────────────────R(1)──────────────○N4")
    print("\t\t  │   8*IR─►                                │")
    print("\t\tN1○────I(1)────────────────────────────────○N4")
    print("\t\t  │         N2         N2    ◄─      ◄─IR   │")
    print("\t\tN1○───R(2)───○─────────○───I(2)──○──R(3)──○N4")
    print("\t\t  │          │          │         N3        │")
    print("\t\t  │         R(4)        │                   │")
    print("\t\t  │          │          │                   │")
    print("\t\t V(1)↑       ○ N4      R(5)                 │")
    print("\t\t  │2*VR      │          │                   │")
    print("\t\t  │        V(2)↑        │                   │")
    print("\t\t  │          │          │                   │")
    print("\t\t  │    ─►    │   IR─►   │      ◄─           │")
    print("\t\tN5○───V(3)───○───R(6)───○─────V(4)─────────○N8")
    print("\t\t  │          N6          N7        ─►       │")
    print("\t\tN5○────────────R(7)──────○───────V(5)──────○N8")
    print("\t\t                         N9")
    print("\t\tCada nodo tiene su voltaje, excepto N2 que es cero por ser el de Tierra:")
    print("\t\tIR = (V4 - V1)/8 = (V7 - V6)/R6 = (V3 - V4)/R3        VR = (V1 - V5)/2\n")

    a, b, c, d, e, f, g, h, i = symbols('V1, V2, V3, V4, V5, V6, V7, V8, V9')
    eq1 = b
    eq2 = f + V2
    eq3 = V2 + e + V3
    eq4 = (I2*R6 + V2) + h + V4
    eq5 = (I2*R6 + V2 + V4) + i + V5
    eq6 = I2*R3 + (c + (I2*R6 + V2 + V4))
    eq7 = I2*R6 + g + V2
    eq8 = I2*R5*R2 - (I2*R6 + V2)*R2 + a*R5
    eq9 = d
    sol1 = solve(eq8)
    sol2 = solve(eq3)
    A = sol1[0]
    B = sol2[0]
    print(solve((eq8, eq1, eq6, eq9, eq3, eq2, eq7, eq4, eq5), (a, b, c, d, e, f, g, h, i)))
    IR = round(-A/8, 2)
    VR = round((A - B)/2, 2)
    print(f"\n\t\tLa solucion es:   IR = {IR}       VR = {VR}")
    encendido = input("\nSi quiere seguir en el programa digite 'Y' caso contrario 'N':   ").upper()
print("\n\n\tF I N  D E L  P R O G R A M A")

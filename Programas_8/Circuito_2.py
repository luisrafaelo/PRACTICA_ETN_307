from sympy import *


def verificador_numerico(orden, Lim_Izquierdo, Lim_Derecho):
    while True:
        try:
            x = float(input(f"\n\tIngrese {orden}: "))
            if not (Lim_Izquierdo < x < Lim_Derecho):
                print(f"\tEl valor no entra en los limites {Lim_Izquierdo} < Numero < {Lim_Derecho}")
                continue
            return x
        except:
            print("\tSolo valores decimales son permitidos (para un entero sera ' .00 ')")
            continue


encendido = "Y"
while not encendido == "N":
    print("\t\t\tC I R C U I T O  NRO.  2")
    print("\n\t\tR = Resistencia       V = Fuenete de voltaje       I = FUente de Corriente")
    # Codigos de Alt + ║186  ═205    ╩202╦203╬206  ╔201╗187  ╝188╚200  ╣185╠204
    # Codigos de Alt + │179  ─196  ┼197 ├195 ┤180  ┌218 ┐191  ┘217 └192  ┴193 ┬194
    # Codigos de Alt + ↑24   ↓25    196─►16     17◄─196
    print("\t\t                  i─►")
    print("\t\t ┌───────────────R(1)────────┐")
    print("\t\t │                           │")
    print("\t\t ├─────┬───R(2)───┬───R(3)───┤")
    print("\t\t │     │          │          │")
    print("\t\t │   R(4)        V(1)↑      R(5)")
    print("\t\t │     │          │          │")
    print("\t\tI(1)↑  │          │          │")
    print("\t\t │     │         R(6)       I(2)↓")
    print("\t\t │     │          │          │")
    print("\t\t └─────┴──────────┴──────────┘")
    R1 = 3
    R2 = 1
    R3 = 4
    R4 = 2
    R5 = 6
    R6 = 5
    V1 = 8
    I1 = 7
    I2 = 9
    while True:
        opcion = input("\n\t\tDesea usar:   A)Valores predeterminados      B)Nuevos Valores\n\t\tOpcion: ").upper()
        if opcion == "A":
            print("\n\t\tPor defecto el circuito tiene los siguientes valores:")
            print("\n\t\tR(1) = 3 ohmios      R(2) = 1 ohmio      R(3) = 4 ohmios")
            print("\t\tR(4) = 2 ohmios       R(5) = 6 ohmios      R(6) = 5 ohmios")
            print("\t\tV(1) = 8 voltios      I(1) = 7 amperios       I(2) = 9 amperios\n")
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
            V1 = verificador_numerico("V(1)", -10000, 10000)
            I1 = verificador_numerico("I(1)", -10000, 10000)
            I2 = verificador_numerico("I(2)", -10000, 10000)
            break
        else:
            continue
    print("\t\tLo que pide el problema es la corriente I en R(1)")
    print("\t\tUsando el metodo de mallas, se analizara el circuito por mallas (M):")
    print("\t\t       I1─►      i─►")
    print("\t\t ┌───────────────R(1)────────┐")
    print("\t\t │            M1             │")
    print("\t\t ├─────┬───R(2)───┬───R(3)───┤")
    print("\t\t │     │          │          │")
    print("\t\t │   R(4)        V(1)       R(5)")
    print("\t\t │     │          │          │")
    print("\t\tI(1)   │    M3    │    M4    │")
    print("\t\t │     │         R(6)       I(2)")
    print("\t\t │ M2  │          │          │")
    print("\t\t └─────┴──────────┴──────────┘")
    print("\t\t  ◄─I2      ◄─I3      ◄─I4")
    print("\t\tCada malla tendra su corriente (I) en sentido horario, y son:\n")
    # I1 es w ||  I2 es x ||  I3 es y ||  I4 es z ||
    w, x, y, z = symbols('I1, I2, I3, I4')
    eq1 = w*(R1 + R2 + R3) - y*R2 - z*R3
    eq2 = V1 + y*(R2 + R4 + R6) - w*R2 - x*R4 - z*R6
    eq3 = x - I1
    eq4 = z - I2
    print(solve((eq1, eq2, eq3, eq4), (w, x, y, z)))
    print("\n\t\tEntonces, la solucion sera I1")
    encendido = input("\nSi quiere seguir en el programa digite 'Y' caso contrario 'N':   ").upper()
print("\n\n\tF I N  D E L  P R O G R A M A")


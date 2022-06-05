import pyodbc, os

encendido = "Y"

while not encendido == "N":
    print ("\n\t\t\tLAB 10, BASE DE DATOS\n")
    
    while True:

        opcion = input("\n\tElija una opcion:\n\tA) Leer los datos\n\tB) Insertar\n\tC) Eliminar\n\tD) Editar\n\t->\t").upper()
        if opcion == "A":
            while True:
                print("\n\tElija una opcion:\n\t1) Leer todo\n\t2) Leer fabricante y categoria\n\t3) Leer por descripcion\n\t4) Ranking de precios\n\t5) Salir->")
                opcion = int(input())
                if opcion == 1:
                    con_string = r'DRIVER={Microsoft Access Driver (*.mdb, *.accdb)};DBQ=C:\Users\itama\OneDrive\Escritorio\PROGRAMAS PYTHON\electronicos.accdb;'
                    conn = pyodbc.connect (con_string)  
                    cur = conn.cursor()
                    cur.execute('SELECT * FROM productos') 
                    for datos in cur.fetchall():
                        print(datos)
                    os.system('pause')
                    break
                if opcion == 2:
                    try:
                        i = 0
                        con_string = r'DRIVER={Microsoft Access Driver (*.mdb, *.accdb)};DBQ=C:\Users\itama\OneDrive\Escritorio\PROGRAMAS PYTHON\electronicos.accdb;'
                        conn = pyodbc.connect (con_string)  
                        cur = conn.cursor()
                        cur.execute('SELECT * FROM productos')
                        while True:
                            try:
                                i = 0
                                for datos in cur.fetchone():
                                    i += 1
                                    if i == 1:
                                        print("\n\tId:\t\t\t\t", end="")
                                        print(datos)
                                    if i == 2:
                                        continue
                                    if i == 3:
                                        print("\n\tFabricante:\t\t", end="")
                                        print(datos)
                                    if 5 <= i <= 6:
                                        continue
                                    if i == 7:
                                        print("\n\tCategoria:\t\t", end="")
                                        print(datos)
                                    if 8 <= i <= 10:
                                        continue
                                print("_________________________________________________\n")
                            except:
                                break
                    except TypeError:
                        print ("Vacio, id disponible")
                        break
                if opcion == 3:
                    try:
                        i = 0
                        con_string = r'DRIVER={Microsoft Access Driver (*.mdb, *.accdb)};DBQ=C:\Users\itama\OneDrive\Escritorio\PROGRAMAS PYTHON\electronicos.accdb;'
                        conn = pyodbc.connect (con_string)
                        cur = conn.cursor()
                        cur.execute('SELECT * FROM productos')
                        frase = input()
                        while True:
                            try:
                                i = 0
                                for datos in cur.fetchone():
                                    i += 1
                                    if i == 1:
                                        print("\n\tId:\t\t\t\t", end="")
                                        print(datos)
                                    if 2 == i or i == 3:
                                        continue
                                    if i == 4:
                                        print("\n\tDescripcion:\t", end="")
                                        print(datos)
                                    if 5 <= i <= 10:
                                        continue
                                print("____________________________________________________________________________________________________________\n")
                            except:
                                break
                    except TypeError:
                        print ("Vacio, id disponible")
                        break
                if opcion == 4:
                    try:
                        con_string = r'DRIVER={Microsoft Access Driver (*.mdb, *.accdb)};DBQ=C:\Users\itama\OneDrive\Escritorio\PROGRAMAS PYTHON\electronicos.accdb;'
                        conn = pyodbc.connect(con_string)
                        cur = conn.cursor()
                        cur.execute('SELECT * FROM productos')
                        precio = []
                        j = 0
                        while True:
                            try:
                                i = 0
                                for datos in cur.fetchone():
                                    i += 1
                                    if 1 <= i <= 5:
                                        continue
                                    if i == 6:
                                        precio[j].append(datos)
                                        j = j + 1
                                    if 7 <= i <= 10:
                                        continue
                            except:
                                break
                        precio.sort(reverse=True)
                        k = 0
                        print("\n\tLa lista de precios es la siguiente:")
                        while True:
                            import random
                            y = random.randrange(1,2705)
                            print(f"\n\tId:\t\t{y}\n\tPrecio:\t{precio[k]}")
                            if k == 10:
                                break
                    except TypeError:
                        print("Vacio, id disponible")
                        break
                if opcion == 5:
                    os.system('pause')
                    break 
        if opcion == "B":
            try:
                con_string =r'DRIVER={Microsoft Access Driver (*.mdb, *.accdb)};DBQ=C:\Users\itama\OneDrive\Escritorio\PROGRAMAS PYTHON\electronicos.accdb;'
                conn =pyodbc.connect(con_string)   
                cursor = conn.cursor()
                print("\n\tid: ")
                ID = int(input())
                print("\n\tIngrese el idnumber: ")
                idnumber = int(input())
                print("\n\tFabricante: ")
                Fabricante = input()
                print("\n\tDescripcion ")
                Descripcion = input()
                print("\n\tratings: ")
                ratings = input()
                print("\n\tprices: ")
                prices = input()
                print("\n\tCategory: ")
                Category = input()
                print("\n\tcpugpu: ")
                cpugpu = input()
                print("\n\tCampo8: ")
                Campo8 = input()
                print("\n\tCampo9: ")
                Campo9 = input()
                
                myProductos = (
                    (ID, idnumber, Fabricante, Descripcion, ratings, prices, Category, cpugpu, Campo8, Campo9 ),
                    )
                
                cursor.executemany('INSERT INTO Productos VALUES (?,?,?,?,?,?,?,?,?,?)',myProductos)
                conn.commit()
                print ('Datos insertados')
            except pyodbc.IntegrityError:
                print ("YA CONTIENE DATOS, NO SE PUEDE REESCRIBIR")
            os.system('pause')
            break
        if opcion == "C":
                con_string = r'DRIVER={Microsoft Access Driver (*.mdb, *.accdb)};DBQ=C:\Users\itama\OneDrive\Escritorio\PROGRAMAS PYTHON\electronicos.accdb;'
                conn = pyodbc.connect (con_string)
                print("\n\tIngrese el id que desea ELIMINAR: ")
                user_id  = int(input())
                
                cur=conn.cursor()
                cur.execute('DELETE FROM productos  WHERE id= ?', (user_id))
                conn.commit()
                print("Datos Eliminados")
                os.system('pause')
                break
        if opcion == "D":
            while True:
                
                    print ("Ingrese el id: ") 
                    user_id = input()
                    print("1)Idnumber, 2)fabricante, 3)Descripcion, 4)ratings, 5)prices, 6)Category, 7)cpugpu, 8)Campo8, 9)Campo9")
                    opcion = int(input())
                    if opcion == 1:
                        
                        con_string = r'DRIVER={Microsoft Access Driver (*.mdb, *.accdb)};DBQ=C:\Users\itama\OneDrive\Escritorio\PROGRAMAS PYTHON\electronicos.accdb;'
                        conn = pyodbc.connect (con_string) 
                        
                        print ("Ingrese los cambios: ") 
                        newname = input()
                
                        cur=conn.cursor()
                        cur.execute('UPDATE productos SET idnumber = ? WHERE id= ?', (newname, user_id))
                        conn.commit()
                        print("datos Actualizados")
                        
                        break
                    if opcion == 2:
                        
                        con_string = r'DRIVER={Microsoft Access Driver (*.mdb, *.accdb)};DBQ=C:\Users\itama\OneDrive\Escritorio\PROGRAMAS PYTHON\electronicos.accdb;'
                        conn = pyodbc.connect (con_string)
                                         
                        print ("Ingrese los cambios: ") 
                        newname = input()
                
                        cur=conn.cursor()
                        cur.execute('UPDATE productos SET fabricante = ? WHERE id= ?', (newname, user_id))
                        conn.commit()
                        print("datos Actualizados")

                        break
                    if opcion == 3:  
                   
                        print ("Ingrese los cambios: ") 
                        newname = input()
                
                        cur = conn.cursor()
                        cur.execute('UPDATE productos SET descripcion = ? WHERE id= ?', (newname, user_id))
                        conn.commit()
                        print("datos Actualizados")
                     
                        break
                    if opcion == 4:  
                 
                        print ("Ingrese los cambios: ") 
                        newname = input()
                
                        cur=conn.cursor()
                        cur.execute('UPDATE productos SET ratings = ? WHERE id= ?', (newname, user_id))
                        conn.commit()
                        print("datos Actualizados")
                        
                        break
                    if opcion == 5:  
                       
                        print ("Ingrese los cambios: ") 
                        newname = input()
                
                        cur=conn.cursor()
                        cur.execute('UPDATE productos SET prices = ? WHERE id= ?', (newname, user_id))
                        conn.commit()
                        print("datos Actualizados")
                        
                        break
                    if opcion == 6:
                        print ("Ingrese los cambios: ") 
                        newname = input()
                
                        cur=conn.cursor()
                        cur.execute('UPDATE productos SET Category = ? WHERE id= ?', (newname, user_id))
                        conn.commit()
                        print("datos Actualizados")
                        
                        break
                    if opcion == 7: 
                        print ("Ingrese los cambios: ") 
                        newname = input()
                
                        cur=conn.cursor()
                        cur.execute('UPDATE productos SET cpugpu = ? WHERE id= ?', (newname, user_id))
                        conn.commit()
                        print("datos Actualizados")
                        
                        break
                    if opcion == 8: 
                        print ("Ingrese los cambios: ") 
                        newname = input()
                
                        cur=conn.cursor()
                        cur.execute('UPDATE productos SET Campo8 = ? WHERE id= ?', (newname, user_id))
                        conn.commit()
                        print("datos Actualizados")
                        
                        break
                    if opcion == 9:  
                        print ("Ingrese los cambios: ") 
                        newname = input()
                
                        cur=conn.cursor()
                        cur.execute('UPDATE productos SET Campo9 = ? WHERE id= ?', (newname, user_id))
                        conn.commit()
                        print("datos Actualizados")
                        
                        break
                    if opcion == 10:
                        os.system('pause')
                    break 
               
        if opcion == "E":
            encendido = input("").upper()
            break
        

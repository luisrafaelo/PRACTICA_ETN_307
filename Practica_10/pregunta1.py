import pyodbc, os, tkinter
encendido = "Y"
while not encendido == "N":
    print ("\n\t\t\tLAB 10, BASE DE DATOS\n")
    
    while True:
        
        opcion = input("\n\tElija una opcion:\n\tA) Leer los datos\n\tB) Insertar\n\tC) Eliminar\n\tD) Editar\n\tE) Estadisticas\n\tF) Listado_descripcion\n\tG) Ranking\n\tH) Foto\n\t->").upper()
        if opcion == "A":
            while True:
                print("\n\tElija una opcion:\n\t1) Leer todo\n\t2) Leer id \n\t3) Salir\n\t->")
                opcion = int(input())
                if opcion == 1:
                    con_string = r'DRIVER={Microsoft Access Driver (*.mdb, *.accdb)};DBQ=C:\Users\docki\Desktop\BaseDatos\electronicos.accdb;'
                    conn = pyodbc.connect (con_string)  
                    cur = conn.cursor()
                    cur.execute('SELECT * FROM productos') 
                    for datos in cur.fetchall():
                        print(datos)  
                    os.system('pause')
                    break
                if opcion == 2:  
                    try:                 
                        con_string = r'DRIVER={Microsoft Access Driver (*.mdb, *.accdb)};DBQ=C:\Users\docki\Desktop\BaseDatos\electronicos.accdb;'
                        conn = pyodbc.connect (con_string)  
                        cur = conn.cursor()
                        user_id = input("\n\tElija un id:\n\t->").upper()
                        cur.execute('SELECT * FROM productos WHERE id =?', (user_id)) 
                        print("Id, Idnumber, fabricante, Descripcion, ratings, prices, Category, cpugpu, Campo8, Campo9")
                        for datos in cur.fetchone():
                            print(datos) 
                    except TypeError:
                        print ("Vacio, id disponible")
                        break
                if opcion == 3:
                    os.system('pause')
                    break 
        if opcion == "B":
            try:
                con_string =r'DRIVER={Microsoft Access Driver (*.mdb, *.accdb)};DBQ=C:\Users\docki\Desktop\BaseDatos\electronicos.accdb;'
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
                con_string = r'DRIVER={Microsoft Access Driver (*.mdb, *.accdb)};DBQ=C:\Users\docki\Desktop\BaseDatos\electronicos.accdb;'
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
                
                con_string = r'DRIVER={Microsoft Access Driver (*.mdb, *.accdb)};DBQ=C:\Users\docki\Desktop\BaseDatos\electronicos.accdb;'
                conn = pyodbc.connect (con_string)
                print ("Ingrese el id: ") 
                user_id = input()
                cur=conn.cursor()
                cur.execute('SELECT * FROM productos WHERE id =?', (user_id)) 
                for datos in cur.fetchall():
                    print(datos) 
                print("1)Idnumber, 2)fabricante, 3)Descripcion, 4)ratings, 5)prices, 6)Category, 7)cpugpu, 8)Campo8, 9)Campo9, 10)Salir")
                opcion = int(input())
                if opcion == 1:
                        
                    
                    print ("Ingrese los cambios: ") 
                    newname = input()
            
                    cur=conn.cursor()
                    cur.execute('UPDATE productos SET idnumber = ? WHERE id= ?', (newname, user_id))
                    conn.commit()
                    print("datos Actualizados")
                    
                    break
                if opcion == 2:
                                        
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
            
                    cur=conn.cursor()
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
            con_string = r'DRIVER={Microsoft Access Driver (*.mdb, *.accdb)};DBQ=C:\Users\docki\Desktop\BaseDatos\electronicos.accdb;'
            conn = pyodbc.connect (con_string)  
            cur = conn.cursor()
            cur.execute('SELECT * FROM productos') 
            for datos in cur.fetchall():
                print(datos)  
            
            break
        if opcion == "F":
            
            break
        if opcion == "G":
            
            break
        if opcion == "H":
            while True:
                print("\nIngrese El id del producto que quiere ver la imagen con .png al final o digite 0 para salir\n->")
                aver = input()
                if aver== '0':
                    os.system('pause')
                    break
                else:
                    try:
                        ventana = tkinter.Tk()

                        img = tkinter.PhotoImage(file = aver)
                        lbl_img = tkinter.Label(ventana, image=img)
                        lbl_img.pack()
                        
                    except tkinter.TclError as e:
                        print("No hay imagen",e)

                        ventana.mainloop()
                               
        break

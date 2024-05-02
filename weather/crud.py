from database import con, cur
import os

def create_zone():
    os.system('clear')
    
    zone_name = input('Zone name: ')
    zone_address = input('Zone address: ')
    zone_gps = input('Zone gps: ')
    zone_descrip = input('Zone description: ')

    new_zone = f'''
        INSERT INTO zones
            (name, address, gps_url, description)
        VALUES
            ('{zone_name}','{zone_address}','{zone_gps}','{zone_descrip}')
    '''
    con.execute(new_zone)
    con.commit()

    print('::: New zone has been created successfully :::')
    key = input('Press any to continue ...')
    #os.system('Pause')
    main_menu()

def list_zones():
    os.system('clear')

    query_list_zones = 'SELECT id, name, address FROM zones'
    cur.execute(query_list_zones)
    data = cur.fetchall()
    
    print("-" * 50)
    print("{:<10} {:<20} {:<10}".format("ID", "NAME", "ADDRESS"))
    print("-" * 50)

    for row in data:
        print("{:<10} {:<20} {:<10}".format(row[0],row[1],row[2]))

    print('\n')
    #print(data)

    key = input('Press any key to continue')
    main_menu()

def main_menu():
    opt_status = True

    os.system('clear')
    print("::: MAIN MENU :::")
    print('[1]. Register zone')
    print('[2]. Register sensor type ')
    print('[3]. Register sensor')
    print('[4]. Salir')

    while opt_status:
        opt = int(input('Press any option: '))
        if opt >= 1 and opt <= 4:
            opt_status = False
        else:
            print('::: Invalid option :::')

    if opt == 1:
        create_zone()
    elif opt == 2:
        list_zones()
    elif opt == 4:
        print('See you soon')
    else:
        print('No more options')

#Main
main_menu()

#Close connection
con.close()
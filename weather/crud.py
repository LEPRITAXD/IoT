from database import con, cur
import os

def crete_zone():
    os.system('clear')

    new_zone = '''
        INSERT INTO zones
            (name, address,  gps_url, description)
        VALUES
        ('CESMAG CATAMBUCO','SEDE CATAMBUCO','https://www.google.com/maps/d/viewer?mid=1Ftf69IEl012DqtAiSvpq-MnC_DA&hl=en_US&ll=1.2153999529064732%2C-77.261063&z=13','ZONA CATAMBUCO')
    
    '''
    con.execute(new_zone)
    con.commit()

    print('::: New zone has been created successfull :::')
    

def list_zones():
    os.system('clear')

    query_list_zones = 'SELECT * FROM zones'
    cur.execute(query_list_zones)
    data = cur.fetchall()
    print(data)
#Main
crete_zone()
list_zones()
#7. Close connection
con.close()


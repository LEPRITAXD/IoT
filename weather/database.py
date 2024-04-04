'''
dev: frank fernandez
Scrip description: database configuration
'''

#1. Import data base engine
import sqlite3

#2. Create database connetion (DB_NAME: wather)
con =  sqlite3.connect('weather.db')

#3. Create cursor objet => Let us excute sql commands
cur = con.cursor()

#4. Create tables  querys
zones_model_query = '''
    CREATE TABLE IF  NOT  EXISTS zones (
        id INTEGER PRIMARY KEY,
        name TEXT NOT NULL,
        address TEXT NULL,
        gps_url TEXT NULL,
        description TEXT NULL,
        status BOOLEAN DEFAULT true,
        created_at TIMESTAMP DEFAULT (datetime('now','localtime')),
        updated_at TIMESTAMP DEFAULT (datetime('now','localtime')),
        deleted_at TIMESTAMP NULL
    );
'''
sensors_model_query = '''
    CREATE TABLE IF NOT EXISTS sensors(
        id INTEGER PRIMARY KEY,
        name TEXT NOT NULL,
        description TEXT NULL,
        datasheet_url TEXT NULL,
        stock_code TEXT NULL,
        status BOOLEAN DEFAULT true,
        zone_id INTEGER NOT NULL DEFAULT 1,
        created_at TIMESTAMP DEFAULT (datetime('now','localtime')),
        updated_at TIMESTAMP DEFAULT (datetime('now','localtime')),
        deleted_at TIMESTAMP NULL
    );
'''

#5. Excute queris
cur.execute(zones_model_query)
cur.execute(sensors_model_query)

#6.  Save  changes in DB => Push to database
con.commit()

#7. Close connection
#con.close()

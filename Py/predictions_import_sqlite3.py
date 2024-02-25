import sqlite3

def create_table():
    # connect to the database, if it doesn't exist it will be created
    conn = sqlite3.connect('predictions.db')

    # create a cursor object
    c = conn.cursor()

    # create table
    c.execute('''CREATE TABLE forecasts
                 (forecast_id INTEGER PRIMARY KEY, 
                 forecast REAL, 
                 outcome REAL, 
                 brier_score REAL,
                 event TEXT,
                 date TEXT)''')

    # commit the changes and close the connection
    conn.commit()
    conn.close()

create_table()

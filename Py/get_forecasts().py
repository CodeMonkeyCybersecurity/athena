def get_forecasts():
    conn = sqlite3.connect('predictions.db')
    c = conn.cursor()
    c.execute("SELECT * FROM forecasts")
    rows = c.fetchall()
    conn.close()
    return rows

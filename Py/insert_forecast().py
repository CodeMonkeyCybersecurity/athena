def insert_forecast(forecast, outcome, brier_score, event, date):
    conn = sqlite3.connect('predictions.db')
    c = conn.cursor()
    c.execute("INSERT INTO forecasts (forecast, outcome, brier_score, event, date) VALUES (?, ?, ?, ?, ?)",
              (forecast, outcome, brier_score, event, date))
    conn.commit()
    conn.close()

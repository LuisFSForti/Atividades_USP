import oracledb
from tabulate import tabulate

dsn = oracledb.makedsn(
    host = '',
    port=,
    service_name = ''
    );
conn = oracledb.connect(user='', password='', dsn=dsn);

cursor = conn.cursor()
cursor.execute("SELECT 'SELECT * FROM '||table_name FROM user_tables")
queries = cursor.fetchall()

for (query, ) in queries:
    print(f"Execuranto: {query}")
    cursor.execute(query)
    
    rows = cursor.fetchall()
    cols = [desc[0] for desc in cursor.description]
    
    print(f"\n==== {query} ====")
    print(tabulate(rows, headers=cols, tablefmt="psql"))

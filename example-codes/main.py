# Transaction Management with Python and PostgreSQL

# A transaction is when we execute multiple SQL statements in a database; all statements must be executed successfully or none at all.
# If all statements are executed successfully, a commit is performed, saving all changes made to the database in that transaction.
# Otherwise, in case of an error, a rollback is performed, undoing all changes made to the database in that transaction.

# The 'with' statement handles this automatically. If 'with' is not used, commit or rollback must be executed manually.

import psycopg
from psycopg.rows import TupleRow
from psycopg.cursor import Cursor

CONNECTION_DATA = "dbname=test_db user=postgres password=admin host=localhost port=5432"

conexion = psycopg.connect(CONNECTION_DATA)
cursor: Cursor[TupleRow] | None = None

try:
    # To demonstrate transaction management, we will manually commit and rollback
    # By default, autocommit is set to False to prevent changes from being saved in case of an error;
    # therefore, it's common to commit manually or use 'with'.
    conexion.autocommit = False

    cursor = conexion.cursor()

    # ------------------------------- Start of the transaction ------------------------------
    # Create the SQL statement
    sql_insert = (
        "INSERT INTO person(first_name, last_name, email, age) VALUES (%s, %s, %s, %s)"
    )
    sql_insert_values = ("Jorge", "Ramirez", "jramirez@mail.com", 27)
    # cursor.execute(sql_insert, sql_insert_values)
    print("Inserting new record...")

    sql_update = "UPDATE person SET first_name = %s, last_name = %s, email = %s WHERE id_person = %s"
    sql_update_values = ("Maria", "Esparza", "mesparza@mail.com", 13)
    cursor.execute(sql_update, sql_update_values)
    print("Updating record...")

    print()
    sql_select = "SELECT * FROM person ORDER BY id_person ASC"
    person_list = list(cursor.execute(sql_select))
    for person in person_list:
        print(person)
    print()
    # ------------------------------- End of the transaction ------------------------------

except Exception as e:
    # If an error occurs, perform rollback
    conexion.rollback()
    print("An error occurred, rollback was performed: ", e)
else:
    # If commit is not executed, changes are not saved to the database
    # If no error occurs, perform commit
    conexion.commit()
    print("Transaction completed successfully.")
finally:
    # Close the cursor and connection
    if cursor is not None:
        cursor.close()
    conexion.close()

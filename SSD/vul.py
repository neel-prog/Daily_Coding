import sqlite3

# Connect to database
conn = sqlite3.connect("users.db")
cursor = conn.cursor()

# Create users table
cursor.execute("""
CREATE TABLE IF NOT EXISTS users (
    id INTEGER PRIMARY KEY,
    username TEXT,
    password TEXT
)
""")

# Add test user
cursor.execute("""
INSERT OR IGNORE INTO users (id, username, password)
VALUES (1, 'admin', 'admin123')
""")

conn.commit()

# Login
username = input("Enter username: ")
password = input("Enter password: ")

# Vulnerable SQL query
query = "SELECT * FROM users WHERE username='" + username + "' AND password='" + password + "'"

print("\nGenerated Query:")
print(query)

cursor.execute(query)

result = cursor.fetchone()

if result:
    print("\nLogin successful!")
    print("User:", result[1])
else:
    print("\nInvalid username or password.")

conn.close()
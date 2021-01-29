import pymysql as sql
import app.db as db
from app.expection import UserException
import hashlib

class User:

    def __init__(self, user_id, username):
        self.user_id = user_id
        self.username = username

    @staticmethod
    def insert(username, password):
        conn = db.get_connection()

        cursor = conn.cursor()
        cursor.execute('SELECT user_id FROM user WHERE username=%s', (username))
        if cursor.fetchone() != None:
            raise UserException('Username already taken.')
        cursor.close()

        cursor = conn.cursor()
        hashed_password = hashlib.sha256(password.encode('utf-8')).hexdigest()
        cursor.execute('INSERT INTO user (username, password) VALUES (%s, %s)',
                       (username, hashed_password))
        conn.commit()
        cursor.close()

        conn.close()

    @staticmethod
    def get(username, password):
        conn = db.get_connection()
        cursor = conn.cursor()
        cursor.execute('SELECT user_id, password FROM user WHERE username=%s', (username))
        result = cursor.fetchone()
        if result == None:
            raise UserException('User not found.')
        cursor.close()
        conn.close()

        (user_id, real_hashed_password) = result
        hashed_password = hashlib.sha256(password.encode('utf-8')).hexdigest()
        if real_hashed_password != hashed_password:
            raise UserException('Incorrect password.')

        return User(user_id, username)

class Task:

    def __init__(self, user_id, task_id, title, begin, end, status):
        self.user_id = user_id
        self.task_id = task_id
        self.title = title
        self.begin = begin
        self.end = end
        self.status = status

    @staticmethod
    def get_user_tasks(user_id):
        tasks = []

        conn = db.get_connection()
        cursor = conn.cursor()
        cursor.execute('SELECT * FROM user_has_task INNER JOIN task ON fk_task_id = task_id WHERE fk_user_id=%s', (str(user_id)))
        results = cursor.fetchall()
        cursor.close()
        conn.close()

        for result in results:
            (fk_user_id, fk_task_id, task_id, title, begin, end, status) = result
            tasks.append(Task(fk_user_id, task_id, title, begin, end, status))

        return tasks

    @staticmethod
    def get_user_task(user_id, task_id):
        conn = db.get_connection()
        cursor = conn.cursor()
        cursor.execute('SELECT * FROM user_has_task INNER JOIN task ON fk_task_id = task_id WHERE fk_user_id=%s AND fk_task_id=%s', (str(user_id), task_id))
        result = cursor.fetchone()
        cursor.close()
        conn.close()

        if result == None:
            return None
        
        (fk_user_id, fk_task_id, task_id, title, begin, end, status) = result
        return Task(fk_user_id, task_id, title, begin, end, status)

    @staticmethod
    def insert(user_id, title):
        conn = db.get_connection()
        cursor = conn.cursor()
        cursor.execute('INSERT INTO task(title) VALUES (%s)', (title))
        cursor.execute('SELECT last_insert_id()')
        task_id = int(cursor.fetchone()[0])
        cursor.execute('INSERT INTO user_has_task(fk_user_id, fk_task_id) VALUES (%s, %s)', (user_id, task_id))
        cursor.close()
        conn.commit()
        conn.close()

    def delete(self):
        conn = db.get_connection()
        cursor = conn.cursor()
        cursor.execute('DELETE FROM task WHERE task_id=%s', (str(self.task_id)))
        cursor.execute('DELETE FROM user_has_task WHERE fk_task_id=%s', (str(self.task_id)))
        cursor.close()
        conn.commit()
        conn.close()

    def update(self):
        conn = db.get_connection()
        cursor = conn.cursor()
        cursor.execute('UPDATE task SET title=%s, status=%s WHERE task_id=%s', (self.title, self.status, str(self.task_id)))
        cursor.close()
        conn.commit()
        conn.close()
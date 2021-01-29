import pymysql
from app import app

def get_connection():
    return pymysql.connect(host=app.config['DATABASE_HOST'],
                        unix_socket=app.config['DATABASE_SOCK'],
                        user=app.config['DATABASE_USER'],
                        password=app.config['DATABASE_PASS'],
                        db=app.config['DATABASE_NAME'])
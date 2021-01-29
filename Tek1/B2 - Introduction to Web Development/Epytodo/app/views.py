from app import app
from app import controllers
from flask import render_template

@app.route('/', methods=['GET'])
@app.route('/index', methods=['GET'])
@app.route('/home', methods=['GET'])
def route_home():
    return controllers.page_home()

@app.route('/login', methods=['GET'])
def route_login():
    return controllers.page_login()

@app.route('/login', methods=['POST'])
def route_form_login():
    return controllers.form_login()

@app.route('/logout', methods=['GET'])
def route_logout():
    return controllers.page_logout()

@app.route('/register', methods=['GET'])
def route_register():
    return controllers.page_register()

@app.route('/register', methods=['POST'])
def route_form_register():
    return controllers.form_register()

@app.route('/tasks', methods=['GET'])
def route_tasks_list():
    return controllers.page_tasks_list()

@app.route('/tasks/<task_id>/delete', methods=['GET'])
def route_task_delete(task_id):
    return controllers.page_task_delete(task_id)

@app.route('/tasks/<task_id>/delete', methods=['POST'])
def route_form_task_delete(task_id):
    return controllers.form_task_delete(task_id)

@app.route('/tasks/create', methods=['GET'])
def route_task_create():
    return controllers.page_task_create()

@app.route('/tasks/create', methods=['POST'])
def route_form_task_create():
    return controllers.form_task_create()

@app.route('/tasks/<task_id>', methods=['GET'])
def route_task_details(task_id):
    return controllers.page_task_details(task_id)

@app.route('/tasks/<task_id>/edit', methods=['GET'])
def route_task_edit(task_id):
    return controllers.page_task_edit(task_id)

@app.route('/tasks/<task_id>/edit', methods=['POST'])
def route_form_task_edit(task_id):
    return controllers.form_task_edit(task_id)
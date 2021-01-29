from flask import render_template, request, redirect, session
from app import app
from app.models import User, Task
from app.expection import UserException

def page_home():
    motd = 'You are not logged in.'
    if 'user_id' in session:
        motd = 'Hello %s' % session['username']

    return render_template('home.html', motd=motd)

def page_register():
    if 'user_id' in session:
        return redirect('/home')
    return render_template('register.html')

def form_register():
    if 'user_id' in session:
        return redirect('/home')
    try:
        username = request.form['username'].strip()
        password = request.form['password']

        if (len(username) < 3):
            raise UserException('Username is too short.')
        if (len(username) > 32):
            raise UserException('Username is too long.')
        if (len(password) < 6):
            raise UserException('Password is too short.')

        User.insert(username, password)
        return redirect('/login')
    except UserException as e:
        return render_template('register.html', error=str(e))
    except Exception as e:
        print(e)
        return render_template('register.html', error='Internal error.')
        
def page_login():
    if 'user_id' in session:
        return redirect('/home')
    return render_template('login.html')

def form_login():
    if 'user_id' in session:
        return redirect('/home')
    try:
        username = request.form['username'].strip()
        password = request.form['password']

        user = User.get(username, password)

        session['user_id'] = user.user_id
        session['username'] = user.username

        return redirect('/home')
    except UserException as e:
        return render_template('login.html', error=str(e))
    except Exception as e:
        print(e)
        return render_template('login.html', error='Internal error.')

def page_logout():
    session.pop('username', None)
    session.pop('user_id', None)
    return redirect('/login')

def page_tasks_list():
    if 'user_id' not in session:
        return redirect('/login')
    tasks = Task.get_user_tasks(session['user_id'])
    return render_template('tasks.html', tasks=tasks)

def page_task_delete(task_id):
    if 'user_id' not in session:
        return redirect('/login')
    try:
        task = Task.get_user_task(session['user_id'], task_id)
        if task == None:
            return 'Task not found'
        return render_template('task_delete.html', task=task)
    except Exception as e:
        print(e)
        return 'Internal server error'

def form_task_delete(task_id):
    if 'user_id' not in session:
        return redirect('/login')
    try:
        task = Task.get_user_task(session['user_id'], task_id)
        if task == None:
            return 'Task not found'
        task.delete()
        return redirect('/tasks')
    except Exception as e:
        print(e)
        return 'Internal server error'

def page_task_create():
    if 'user_id' not in session:
        return redirect('/login')
    return render_template('task_create.html')

def form_task_create():
    if 'user_id' not in session:
        return redirect('/login')
    try:
        Task.insert(session['user_id'], request.form['title'])
        return redirect('/tasks')
    except Exception as e:
        print(e)
        return render_template('task_create.html', error='Internal server error')

def page_task_details(task_id):
    if 'user_id' not in session:
        return redirect('/login')
    try:
        task = Task.get_user_task(session['user_id'], task_id)
        if task == None:
            return 'Task not found'
        return render_template('task_details.html', task=task)
    except Exception as e:
        print(e)
        return 'Internal server error'

def page_task_edit(task_id):
    if 'user_id' not in session:
        return redirect('/login')
    try:
        task = Task.get_user_task(session['user_id'], task_id)
        if task == None:
            return 'Task not found'
        return render_template('task_edit.html', task=task)
    except Exception as e:
        print(e)
        return 'Internal server error'

def form_task_edit(task_id):
    if 'user_id' not in session:
        return redirect('/login')
    try:
        task = Task.get_user_task(session['user_id'], task_id)
        if task == None:
            return 'Task not found'
        task.title = request.form['title']
        task.status = request.form['status']
        task.update()
        return redirect('/tasks/%s' % str(task_id))
    except Exception as e:
        print(e)
        return 'Internal server error'
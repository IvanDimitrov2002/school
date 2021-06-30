from flask import Flask, render_template
app = Flask(__name__)

db = [(1, 'Post 1', 'Gosho', 'Content')]

@app.route('/')
def hello_world():
    return 'Hello World!!!'

@app.route('/posts')
def list_posts():
    return render_template('posts.html', posts=db)

@app.route('/posts/<int:id>')
def show_post(id):
    post = [post for post in db if post[0] == id][0]
    return render_template('post.html', post=post)


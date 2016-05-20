from flask import Flask, url_for, render_template, abort
from flaskext.markdown import Markdown


app = Flask(__name__)
md = Markdown(app, extensions=['extra'])

# Function to easily find your assets
# In your template use <link rel=stylesheet href="{{ static('filename') }}">
app.jinja_env.globals['static'] = (
    lambda filename: url_for('static', filename=filename)
)


@app.route('/')
def presentation():
    return render_template('presentation.html')


@app.route('/methodologie.html')
def methodologie():
    return render_template('methodologie.html')


@app.route('/resultats.html')
def resultats():
    return render_template('resultats.html')


@app.route('/apropos.html')
def apropos():
    return render_template('apropos.html')


@app.route('/brasseurs.html')
def brasseurs():
    return render_template('brasseurs.html')


@app.route('/consommateurs.html')
def consommateurs():
    return render_template('consommateurs.html')


@app.route('/conclusion.html')
def conclusion():
    return render_template('conclusion.html')


@app.route('/graph-<name>-<layout>.html')
def graph(name, layout):
    if (
        name not in ['brasseurs', 'consommateurs'] or
        layout not in ['forceatlas', 'openord', 'layered']
    ):
        abort(404)
    return render_template('graph.html', name=name, layout=layout)


if __name__ == "__main__":
    app.run(debug=True)

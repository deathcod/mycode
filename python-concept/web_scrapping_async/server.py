from time import sleep

from flask import Flask, Response, request


app = Flask(__name__)


message = b'Hello PyTennessee! ' * 100 + b'\n'
CHUNK_LEN = 100
N_CHUNKS = len(message) / CHUNK_LEN

@app.route("/", methods = ['GET', 'POST'])
def hello():
    sec = request.args.get("sec")
    sleep(float(sec))
    wait_time = "Waited for {:4.2f} seconds.".format(float(sec))
    return Response(wait_time)

if __name__ == "__main__":
    app.run(threaded=True)

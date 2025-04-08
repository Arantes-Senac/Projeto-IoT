import cv2
import firebase_admin
from firebase_admin import credentials, db, storage
from datetime import datetime
import time

# Inicializar Firebase
cred = credentials.Certificate("credenciais.json")  # baixe do Firebase
firebase_admin.initialize_app(cred, {
    'databaseURL': 'https://SEU_PROJETO.firebaseio.com/',
    'storageBucket': 'SEU_PROJETO.appspot.com'
})

# Caminho do RTSP
rtsp_url = "rtsp://usuario:senha@IP_DA_CAMERA:554/av_stream"

# Pega a informação do sensor PIR no Firebase
ref = db.reference("alertas/movimento")

ultima_alerta = ""

while True:
    alerta = ref.get()
    if alerta != ultima_alerta and alerta:  # Novo alerta
        print("🚨 Movimento detectado, capturando imagem...")
        ultima_alerta = alerta

        cap = cv2.VideoCapture(rtsp_url)
        ret, frame = cap.read()
        if ret:
            nome_arquivo = datetime.now().strftime("pir(dataehora).jpg")
            local_path = f"capturas/{nome_arquivo}"
            cv2.imwrite(local_path, frame)
            print(f"✅ Imagem salva: {local_path}")

            # Enviar para Firebase Storage
            bucket = storage.bucket()
            blob = bucket.blob(f"imagens/{nome_arquivo}")
            blob.upload_from_filename(local_path)
            print("☁️ Enviada para Firebase Storage.")
        else:
            print("❌ Falha ao capturar imagem.")
        cap.release()

    time.sleep(2)

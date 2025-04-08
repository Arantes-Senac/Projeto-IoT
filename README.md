# Projeto Integrador de IoT - Sistema de Segurança Residencial Inteligente

## 📌 Objetivo do Projeto
Desenvolver um sistema de segurança residencial utilizando tecnologias de Internet das Coisas (IoT), que combine sensores de presença PIR, câmeras IP e uma fechadura inteligente. O sistema será capaz de:

- Monitorar a parte externa da residência com uma câmera inteligente.  
- Detectar a presença na parte interna com sensores PIR.  
- Controlar o acesso por meio de uma fechadura inteligente.  
- Registrar imagens de pessoas que conseguirem passar pela porta com o disparo dos sensores.  

---

## 🧰 Componentes Utilizados

### 🔌 Hardware
- **ESP32** — Microcontrolador principal para integração dos sensores  
- **4 sensores PIR** — Para detecção de presença no interior da casa  
- **Câmera SONOFF GK-200MP2-B** — Monitoramento da parte externa (com suporte a RTSP)  
- **Fechadura Intelbras FR 101** — Controle de acesso da porta principal  
- **Fonte de alimentação 5V e 12V** — Para os dispositivos  
- **Nobreak** — Para garantir funcionamento contínuo mesmo em quedas de energia  
- **Cabos, protoboard, conectores** — Para montagem e conexões

### 💻 Software
- **Arduino IDE** — Programação do ESP32  
- **Firebase (Google)** — Registro de eventos e envio de alertas em tempo real  
- **Servidor local (Python + OpenCV ou biblioteca RTSP)** — Captura de imagens da câmera IP interna  

---

## ⚙️ Funcionamento do Sistema

### 🔍 1. Monitoramento Externo (Prevenção)
- A câmera SONOFF externa transmite imagens 24h em tempo real  
- Pode enviar alertas via app da SONOFF ou ser integrada via RTSP para gravação local  

### 🛡️ 2. Detecção Interna (Reação)
- Sensores PIR monitoram Entrada/Sala, Cozinha e Quarto(s)  
- Quando detectam movimento, o ESP32:
  - Envia alerta para o Firebase  
  - Aciona câmera IP interna  
  - Salva ou envia a imagem para o Firebase  

### 🔐 3. Controle de Acesso
- A fechadura FR 101 atua como primeira barreira  
- Caso ultrapassada, sensores PIR ativam o sistema e a câmera registra a ação  

---

## ✅ Resultados Esperados
- Detecção eficiente em tempo real  
- Registro automático de imagens  
- Controle via aplicativo remoto  
- Baixo custo e fácil expansão  

---

## 🚀 Possibilidades de Expansão
- Sensores de abertura de portas e janelas  
- Integração com Google Assistant ou Alexa  
- Histórico de acessos e imagens em banco de dados  
- Ações automatizadas como acender luzes ou ativar sirenes  

---

## 📚 Referências
- [Documentação ESP32 - Espressif](https://docs.espressif.com)  
- [Firebase Documentation](https://firebase.google.com/docs)  
- [SONOFF GK-200MP2-B - RTSP Support](https://sonoff.tech)  
- [Manual Intelbras FR 101](https://www.intelbras.com/pt-br/produto/fechadura-digital-fr-101)  

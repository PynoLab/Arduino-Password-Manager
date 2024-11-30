## **Descrizione del progetto**

Questo progetto consiste in un **Password Manager** sicuro, basato su **Arduino Micro**. Il dispositivo consente di archiviare e recuperare facilmente le password.

### **Componenti:**

1. **Adattatore microSD**  
2. **Keypad a 5 pulsanti**  
3. **Display LCD**  

---

## **Funzionamento**

1. **Preparazione dei File**  
   - L'utente crea file di testo sulla microSD per un servizio o un'applicazione, ognuno con la rispettiva password salvata.

2. **Navigazione nel Menu**  
   - L'utente può navigare nel menu attraverso il **keypad a 5 pulsanti**. Quando seleziona un file, Arduino invia la password corrispondente al dispositivo di destinazione come se fosse una tastiera.

---

## **Esempio di utilizzo**

1. Creare 3 file sulla microSD chiamati: `Insta`, `Mail`, `TikTok`.  
2. In ogni file, salvare la relativa password

3. Quando è necessario inserire una password (ad esempio, per accedere alla casella email), l'utente seleziona il file `Mail`. Arduino invierà automaticamente la password come se fosse digitata tramite una tastiera.

---

## **Comodità e Sicurezza**

- Questo dispositivo è estremamente comodo per memorizzare e utilizzare le password senza doverle ricordare o scrivere manualmente ogni volta.  
- Non è necessario un software complesso o un'app per accedere alle password; basta connettere Arduino al computer e selezionare il file desiderato.  
- Tutte le password sono memorizzate localmente sulla microSD e non sono accessibili da internet o da dispositivi esterni. Il dispositivo Arduino invia i dati solo tramite la porta seriale, quindi non c'è rischio di accessi non autorizzati via rete.  
- L'unico modo per accedere ai dati è rubare fisicamente il dispositivo.  
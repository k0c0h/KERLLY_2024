const express = require("express");
const mongoose = require("mongoose");

const app = express();
const port = 3007;

mongoose.connect('mongodb+srv://SrJCBM:OOP14539ODS@firstdb.gtv30gi.mongodb.net/CreateKeyboards', { 
  useNewUrlParser: true, 
  useUnifiedTopology: true 
});

const db = mongoose.connection;
db.on("error", (error) => console.error("Error de conexión a MongoDB:", error));
db.once("open", () => console.log("Sistema conectado a la base de datos MongoDB"));

app.use(express.json());

app.use(express.static('public'));
const keyboardRouter = require("./routes/keyboardsRoutes");

app.use("/keyboards", keyboardRouter);

app.listen(port, () => console.log(`Servidor de teclados está corriendo en el puerto ${port}`));

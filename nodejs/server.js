const express = require("express");
const app = express();



app.use(express.static('./public'));

app.get("/index",(req,res)=>{
	var response={
		"my name": req.query.led1,
		"my id" :req.query.status
	}
	res.send(response)
})


const PORT = process.env.PORT || 8080;
app.listen(PORT,() =>{
	console.log(`Server is running on port ${PORT}.`);
});



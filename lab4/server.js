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

function controlLED(LED,POWER){

	let child_process = require("child_process");	//導入模組

	let process = child_process.exeFile('sudo',[	
		".C++/main",LED,POWER
	]);												//執行程式
	process.stdout.on('data',(data)=>{				
		console.log(`stdout: ${data}`);
	});												//監聽輸出
	process.stderr.on('data',(data)=>{
		console.log(`stderr: ${data}`);
	});												//監聽錯誤
}

const PORT = process.env.PORT || 8080;
app.listen(PORT,() =>{
	console.log(`Server is running on port ${PORT}.`);
});



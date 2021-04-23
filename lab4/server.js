const express = require("express");
const app = express();

app.use(express.static('./public'));

app.get("/index",(req,res)=>{
	var response={
		"my led1": req.query.LED,
		"my radio" :req.query.status
	}
	res.send(response)
	controlLED(req.query.LED,req.query.status)
	
});
	

app.get("/shine",(req,res)=>{
	var response={
		"my times" :req.query.times
	}
	shine(req.query.times)
	res.send(response)
});

function controlLED(LED,POWER){
	let child_process = require("child_process");	//導入模組
	if(Array.isArray(LED)){
		LED.forEach(function(item, i) { 
			let process = child_process.execFile('sudo',[	
				"./C++/main",item,POWER
			]);	
		});	
	}
	else{
		let process = child_process.execFile('sudo',[	
			"./C++/main",LED,POWER
		]);	
	}

	process.stdout.on('data',(data)=>{				
		console.log(`stdout: ${data}`);
	});												//監聽輸出
	process.stderr.on('data',(data)=>{
		console.error(`stderr: ${data}`);
	});												//監聽錯誤
}

function shine(times){
	let child_process = require("child_process");	//導入模組

	let process = child_process.execFile('sudo',[	
		"./C++/main","shine",times
	]);												//執行程式

	process.stdout.on('data',(data)=>{				
		console.log(`stdout: ${data}`);
	});												//監聽輸出
	process.stderr.on('data',(data)=>{
		console.error(`stderr: ${data}`);
	});												//監聽錯誤
}

const PORT = process.env.PORT || 8080;
app.listen(PORT,() =>{
	console.log(`Server is running on port ${PORT}.`);
});



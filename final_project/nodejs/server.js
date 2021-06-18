const express = require("express");
const app = express();

app.use(express.static('./public'));

app.get("/index",(req,res)=>{
	var response={
		"my led1": req.query.LED,
		"my radio" :req.query.times
	}
	res.send(response)
	shine(req.query.LED,req.query.times)
	
});
	



function shine(LED,times){
	let child_process = require("child_process");	//導入模組
	var str = "";
	var status = ['0', '0', '0', '0']
	if(Array.isArray(LED)){
		LED.forEach(function(item, i) { 
			if(item == "LED1")
			{
				status[0] = '1';
			}
			if(item == "LED2")
			{
				status[1] = '1';
			}
			if(item == "LED3")
			{
				status[2] = '1';
			}
			if(item == "LED4")
			{
				status[3] = '1';
			}
		});
	}
	else
	{
		if(LED == "LED1")
		{
			status[0] = '1';
		}
		if(LED == "LED2")
		{
			status[1] = '1';
		}
		if(LED == "LED3")
		{
			status[2] = '1';
		}
		if(LED == "LED4")
		{
			status[3] = '1';
		}
	}
	console.log(status);
	status.forEach(function(item, i) { 
		str = str + item;
	});
	console.log(str);
	let process = child_process.execFile('sudo',[	
			"./C++/lab6_semaphore.o",str,times
	]);

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



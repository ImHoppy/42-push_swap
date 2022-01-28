const isSorted = arr => arr.every((v,i,a) => !i || a[i-1] <= v);
function checkIfArrayIsUnique(myArray) {
	return myArray.length === new Set(myArray).size;
}

var arr = [];
arr.forEach((elem)=>
{
	if (!isSorted(elem))
		if (checkIfArrayIsUnique(elem))
			result.push(elem);
})
process.stdout.write("(");
result.forEach((e) => {
	process.stdout.write("\"");
	e.forEach((elem) => {process.stdout.write(elem + (e[e.length - 1] == elem ? "" : " "));})
	process.stdout.write( "\""+(result[result.length - 1] == e ? "" : " "));
})
process.stdout.write(")\n");

// https://tio.run/##y0rNyan8///hzun///83/m8MAA
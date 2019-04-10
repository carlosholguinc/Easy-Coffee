function getLink() {
    var char = document.getElementsByClassName('gadget color2');
	var links= char[0].getElementsByClassName('issue-link');
	var linksFilter = links[0].getElementsByTagName('a'), hrefs = [];
	for (var i = 0; i<links.length; i++)
	{   
	    hrefs.push(links[i].href);
	}
	let unique = [...new Set(hrefs)];
	console.log(unique);
}
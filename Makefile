upload: 
	git pull
	git add . 
	read MESSAGE; \
	git commit -m "$$MESSAGE"
	git push

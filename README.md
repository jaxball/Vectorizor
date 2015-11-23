## Vectorizor
A full-stack webdev project started at Make Hacks and finished at... well it's ongoing :)

- **Author**: Jason Lin
- **Languages used**: C++, JavaScript (JSON), HTML/CSS
- **Website**: www.vectorizor.com
- **Latest update**: Nov 22 2015 5:50PM PST

###Code Organization###

**Directory structure**

---

	> include
		> temp
	> test 
		> temp
	> assets
		> js
		> css
	> vtrize.nmf
	> vtrize.hpp
	> vtrize.cpp
	> vtrize_instance.hpp (hpp w/ implementation) 
	> processor.hpp
	> processor_houghline.cpp
	> url_loader_handler.hpp
	> url_loader_handler.cpp
	> singleton_factory.hpp
	> text_processor.cpp (where main is located)
	> instance_factory.hpp
	> photo.js
	> Makefile
	
	

**Frameworks & Libraries**

NaCl (Google Native Client), RapidJSON, PepperJS

UI: Twitter Bootstrap 3
###Backend###

---

	> app.py
	> *textsearch.txt
	> alchemyapi.py
	> api_key.txt

#####PNaCl####
Using the REST API

###OpenCV###

#####Hough Transform#####
Hough Space vs. Cartesian Space

A line can be detected by finding the number of intersections between curves.The more curves intersecting means that the line represented by that intersection have more points. In general, we can define a threshold of the minimum number of intersections needed to detect a line.


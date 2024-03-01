.PHONY: build
build: lily moonlander

.PHONY: lily
lily:
	CONVERT_TO=liatris qmk compile "users/KoFish/plywood2-tarmak3.json"

.PHONY: moonlander
moonlander:
	qmk compile "users/KoFish/plywood2-tarmak3-moonlander.json"

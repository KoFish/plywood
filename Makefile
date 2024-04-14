.PHONY: build
build: lily moonlander

.PHONY: lily
lily:
	CONVERT_TO=liatris qmk compile "users/KoFish/splitkb_aurora_lily58_rev1_kofish.json"

.PHONY: lily-alpha
lily-alpha:
	CONVERT_TO=liatris qmk compile "users/KoFish/plywood2-colemak-alpha.json"

.PHONY: moonlander
moonlander:
	qmk compile "users/KoFish/plywood2-colemak-moonlander.json"

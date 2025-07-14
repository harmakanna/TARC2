PresentTown_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, PresentTown_OnLoad
	.byte 0

PresentTown_OnLoad:
	givemon SPECIES_GROWLITHE, 48
	givemon SPECIES_TOXICROAK, 48
	end
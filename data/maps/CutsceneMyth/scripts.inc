CutsceneMyth_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CutsceneMyth_OnFrame
	.byte 0

CutsceneMyth_OnFrame:
	map_script_2 VAR_CUTSCENE_STATE, 9, CutsceneMyth_Event
	.2byte 0

CutsceneMyth_Event::
	lockall
	setvar VAR_0x8004, 16
	setvar VAR_0x8005, 14
	special TeleportCamera
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, Myth_Movement_CameraPanDiagonalDownSetScene
	playbgm MUS_DP_LAKE_CAVERNS, FALSE
	fadescreen FADE_FROM_BLACK
	message Myth_Text_LongAgo
	waitmessage
	delay 80
	closemessage
	delay 40
	fadescreen FADE_TO_BLACK
	delay 60
	setvar VAR_0x8004, 31
	setvar VAR_0x8005, 22
	special TeleportCamera
	applymovement LOCALID_CAMERA, Myth_Movement_CameraPanUpTornadus
	fadescreen FADE_FROM_BLACK
	delay 20
	playmoncry SPECIES_TORNADUS, CRY_MODE_NORMAL
	message Myth_Text_SpiritOfWind
	waitmessage
	delay 60
	closemessage
	delay 40
	fadescreen FADE_TO_BLACK
	delay 60
	setvar VAR_0x8004, 16
	setvar VAR_0x8005, 21
	special TeleportCamera
	applymovement LOCALID_CAMERA, Myth_Movement_CameraPanDownThundurus
	fadescreen FADE_FROM_BLACK
	delay 20
	playmoncry SPECIES_THUNDURUS, CRY_MODE_NORMAL
	message Myth_Text_SpiritOfStorms
	waitmessage
	delay 60
	closemessage
	delay 40
	fadescreen FADE_TO_BLACK
	delay 60
	removeobject LOCALID_MYTH_TORNADUS
	removeobject LOCALID_MYTH_THUNDURUS
	setobjectxyperm LOCALID_MYTH_TORNADUS, 30, 23
	setobjectxyperm LOCALID_MYTH_THUNDURUS, 12, 23
	setobjectmovementtype LOCALID_MYTH_TORNADUS, MOVEMENT_TYPE_WALK_IN_PLACE_LEFT
	setobjectmovementtype LOCALID_MYTH_THUNDURUS, MOVEMENT_TYPE_WALK_IN_PLACE_RIGHT
	addobject LOCALID_MYTH_TORNADUS
	addobject LOCALID_MYTH_THUNDURUS
	setvar VAR_0x8004, 21
	setvar VAR_0x8005, 23
	special TeleportCamera
	fadescreen FADE_FROM_BLACK
	delay 20
	message Myth_Text_FightEndlessly
	applymovement LOCALID_MYTH_TORNADUS, Myth_Movement_TornadusFightThundurus
	applymovement LOCALID_MYTH_THUNDURUS, Myth_Movement_ThundurusFightTornadus
	playmoncry SPECIES_TORNADUS, CRY_MODE_NORMAL
	waitmoncry
	playmoncry SPECIES_THUNDURUS, CRY_MODE_NORMAL
	waitmoncry
	delay 60
	closemessage
	playmoncry SPECIES_TORNADUS, CRY_MODE_NORMAL
	waitmoncry
	playmoncry SPECIES_THUNDURUS, CRY_MODE_NORMAL
	waitmoncry
	delay 60
	fadescreen FADE_TO_BLACK
	delay 60
	setvar VAR_0x8004, 9
	setvar VAR_0x8005, 5
	special TeleportCamera
	applymovement LOCALID_CAMERA, Myth_Movement_CameraPanHumansPokemon
	fadescreen FADE_FROM_BLACK
	delay 20
	message Myth_Text_Humans
	applymovement LOCALID_MYTH_MAN2, Myth_Movement_Man2HideInCave
	waitmovement 0
	applymovement LOCALID_MYTH_MAN, Myth_Movement_ManHideInCave
	applymovement LOCALID_MYTH_WOMAN, Myth_Movement_WomanHideInCave
	delay 70
	message Myth_Text_Pokemon
	delay 40
	applymovement LOCALID_MYTH_KECLEON, Myth_Movement_KecleonDisappears
	delay 60
	applymovement LOCALID_MYTH_BUNNELBY_RIGHT, Myth_Movement_BunnelbyRRunToForest
	applymovement LOCALID_MYTH_BUNNELBY_RIGHT, Myth_Movement_BunnelbyLRunToForest
	delay 60
	closemessage
	delay 40
	fadescreen FADE_TO_BLACK
	delay 60
	removeobject LOCALID_MYTH_TORNADUS
	removeobject LOCALID_MYTH_THUNDURUS
	setobjectxyperm LOCALID_MYTH_LANDORUS, 21, 17
	setobjectxyperm LOCALID_MYTH_TORNADUS, 24, 23
	setobjectxyperm LOCALID_MYTH_THUNDURUS, 18, 23
	setobjectxyperm LOCALID_MYTH_CELEBI, 8, 22
	setobjectmovementtype LOCALID_MYTH_TORNADUS, MOVEMENT_TYPE_WALK_IN_PLACE_LEFT
	setobjectmovementtype LOCALID_MYTH_TORNADUS, MOVEMENT_TYPE_WALK_IN_PLACE_RIGHT
	addobject LOCALID_MYTH_TORNADUS
	addobject LOCALID_MYTH_THUNDURUS
	message Myth_Text_AsIfFromTheHeavens
	waitmessage
	delay 60
	closemessage
	playmoncry SPECIES_LANDORUS, CRY_MODE_NORMAL
	waitmoncry
	delay 50
	setvar VAR_0x8004, 21
	setvar VAR_0x8005, 23
	special TeleportCamera
	fadescreen FADE_FROM_BLACK
	delay 40
	applymovement LOCALID_MYTH_LANDORUS, Myth_Movement_LandorusEnterScene
	waitmovement
	delay 60
	playmoncry SPECIES_LANDORUS, CRY_MODE_NORMAL
	applymovement LOCALID_MYTH_LANDORUS, Myth_Movement_LandorusBeatTorn
	waitmovement 0
	applymovement LOCALID_MYTH_TORNADUS, Myth_Movement_TornadusBeatenByLandorus
	waitmovement 0
	delay 30
	playmoncry SPECIES_LANDORUS, CRY_MODE_NORMAL
	applymovement LOCALID_MYTH_LANDORUS, Myth_Movement_LandorusBeatThund
	applymovement LOCALID_MYTH_THUNDURUS, Myth_Movement_ThundurusBeatenByLandorus
	delay 60
	message Myth_Text_LandorusCameDown
	waitmessage
	delay 100
	closemessage
	fadeoutbgm 0
	setweather WEATHER_NONE
	doweather
	applymovement LOCALID_MYTH_TORNADUS, Myth_Movement_TornadusFlee
	applymovement LOCALID_MYTH_THUNDURUS, Myth_Movement_ThundurusFlee
	delay 120
	removeobject LOCALID_MYTH_TORNADUS
	removeobject LOCALID_MYTH_THUNDURUS
	message Myth_Text_WithTheSpiritsQuelled
	applymovement LOCALID_CAMERA, Myth_Movement_PanCameraToCelebi
	applymovement LOCALID_MYTH_CELEBI, Myth_Movement_CelebiEnterScene
	delay 80
	closemessage
	fadescreen FADE_TO_BLACK
	delay 60
	playmoncry SPECIES_CELEBI, CRY_MODE_NORMAL
	special ReturnCameraToPlayer
	special RemoveCameraObject
	clearflag FLAG_SYS_NO_MUSIC_ON_TRANSITION
	warpsilent MAP_CUTSCENE_TOWN, 56, 41
	waitstate
	end


Myth_Movement_CameraPanDiagonalDownSetScene:
	walk_diag_southeast
	walk_diag_southeast
	walk_diag_southeast
	walk_diag_southeast
	walk_diag_southeast
	walk_diag_southeast
	walk_diag_southeast
	walk_diag_southeast
	walk_diag_southeast
	walk_diag_southeast
	step_end

Myth_Movement_CameraPanUpTornadus:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Myth_Movement_CameraPanDownThundurus:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Myth_Movement_TornadusFightThundurus:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	face_up
	lock_facing_direction
	walk_down
	walk_down
	walk_down
	delay_16
	delay_16
	delay_16
	unlock_facing_direction
	walk_faster_up
	walk_faster_up
	walk_faster_up
	face_right
	lock_facing_direction
	walk_right
	walk_right
	walk_right
	unlock_facing_direction
	step_end

Myth_Movement_ThundurusFightTornadus:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	face_down
	lock_facing_direction
	walk_up
	walk_up
	walk_up
	delay_16
	delay_16
	delay_16
	unlock_facing_direction
	walk_faster_down
	walk_faster_down
	walk_faster_down
	face_left
	lock_facing_direction
	walk_left
	walk_left
	walk_left
	unlock_facing_direction
	step_end

Myth_Movement_CameraPanHumansPokemon:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Myth_Movement_Man2HideInCave:
	walk_up
	set_invisible
	step_end

Myth_Movement_ManHideInCave:
	delay_16
	delay_16
	walk_up
	walk_up
	set_invisible
	step_end

Myth_Movement_WomanHideInCave:
	delay_16
	delay_16
	walk_right
	walk_up
	walk_up
	set_invisible
	step_end

Myth_Movement_KecleonDisappears:
	set_invisible
	delay_4
	set_visible
	delay_4
	set_invisible
	delay_4
	set_visible
	delay_4
	set_invisible
	delay_4
	set_visible
	delay_8
	set_invisible
	delay_8
	set_visible
	delay_8
	set_invisible
	delay_8
	set_visible
	delay_16
	set_invisible
	step_end

Myth_Movement_BunnelbyRRunToForest:
	jump_in_place_left
	jump_in_place_left
	delay_16
	jump_up
	jump_up
	jump_right
	jump_right
	jump_right
	set_invisible
	step_end

Myth_Movement_BunnelbyLRunToForest:
	delay 16
	delay_16
	jump_right
	jump_up
	jump_up
	jump_right
	jump_right
	jump_right
	set_invisible
	step_end

Myth_Movement_LandorusEnterScene:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Myth_Movement_LandorusBeatTorn:
	walk_faster_down
	walk_faster_left
	walk_faster_left
	walk_faster_left
	lock_facing_direction
	walk_right
	walk_right
	unlock_facing_direction
	step_end

Myth_Movement_TornadusBeatenByLandorus:
	lock_facing_direction
	walk_faster_left
	walk_faster_left
	walk_faster_left
	unlock_facing_direction
	step_end
	
Myth_Movement_LandorusBeatThund:
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	lock_facing_direction
	walk_left
	walk_left
	step_end

Myth_Movement_ThundurusBeatenByLandorus:
	lock_facing_direction
	walk_faster_right
	walk_faster_right
	walk_faster_right
	unlock_facing_direction
	step_end

Myth_Movement_TornadusFlee:
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_right
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	step_end

Myth_Movement_ThundurusFlee:
	delay_16
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_left
	walk_faster_down
	walk_faster_down
	step_end

Myth_Movement_CelebiEnterScene:
	delay_16
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	delay_16
	face_left
	delay_16
	delay_16
	delay_16
	face_right
	step_end
	
Myth_Movement_PanCameraToCelebi:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

@Pan over an empty forest
Myth_Text_LongAgo:
	.string "Long ago, Porta Bella was nothing\n"
	.string "more than a turbulent wasteland on\l"
	.string "a stormy ocean bay.$"

@Pan down to Tornadus
Myth_Text_SpiritOfWind:
	.string "The Spirit of Wind claimed\n"
	.string "the territority of the forest…$"

@Pan up to Thundurus
Myth_Text_SpiritOfStorms:
	.string "…While the Spirit of Lightning claimed\n"
	.string "dominion over the bay.$"

@Genies at each others' throats
Myth_Text_FightEndlessly:
	.string "They were locked in an endless battle\n"
	.string "for the right to rule the land.$"

@Pan over humans and Pokemon
Myth_Text_Humans:
	.string "Humans hunkered down in caves.$"

Myth_Text_Pokemon:
	.string "Pokémon feared being the target of\n"
	.string "a spirit's wrath.$"

@Landorus enters shot of genies fighting, beats them up.
Myth_Text_AsIfFromTheHeavens:
	.string "Then, as if from the heavens…$"

Myth_Text_LandorusCameDown:
	.string "Landorus came down, and quelled the\ln"
	.string "two fighting spirits.$"

@Celebi Enters Shot
Myth_Text_WithTheSpiritsQuelled:
	.string "With the spirits pacified, so too\n"
	.string "appeared Celebi…$"


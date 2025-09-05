CutsceneMyth_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CutsceneMyth_OnFrame
	.byte 0

CutsceneMyth_OnFrame:
	map_script_2 VAR_CUTSCENE_STATE, 11, CutsceneMyth_Event
	.2byte 0

CutsceneMyth_Event::
	lockall
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, Myth_Movement_PositionCameraToFirstShot
	waitmovement 0
	delay 160
	speakername NULL
	message Myth_Text_LongAgo
	@delay 10
	applymovement LOCALID_CAMERA, Myth_Movement_CameraPanDiagonalDownSetScene
	playbgm MUS_DP_LAKE_CAVERNS, FALSE
	fadescreen FADE_FROM_BLACK
	delay 240
	closemessage
	fadescreen FADE_TO_BLACK
	delay 80
	waitmovement LOCALID_CAMERA
	clearflag FLAG_HIDE_FIRST_PAN
	addobject LOCALID_MYTH_TORNADUS
	addobject LOCALID_MYTH_THUNDURUS
	applymovement LOCALID_MYTH_TORNADUS, Myth_Movement_FlyInPlace
	applymovement LOCALID_CAMERA, Myth_Movement_PositionCameraToSecondShot
	waitmovement 0
	applymovement LOCALID_CAMERA, Myth_Movement_CameraPanUpTornadus
	fadescreen FADE_FROM_BLACK
	delay 20
	playmoncry SPECIES_TORNADUS, CRY_MODE_NORMAL
	message Myth_Text_SpiritOfWind
	waitmessage
	delay 100
	closemessage
	delay 40
	fadescreen FADE_TO_BLACK
	applymovement LOCALID_CAMERA, Myth_Movement_PositionCameraToThirdShot
	waitmovement 0
	applymovement LOCALID_MYTH_THUNDURUS, Myth_Movement_FlyInPlace
	applymovement LOCALID_CAMERA, Myth_Movement_CameraPanDownThundurus
	fadescreen FADE_FROM_BLACK
	delay 20
	playmoncry SPECIES_THUNDURUS, CRY_MODE_NORMAL
	message Myth_Text_SpiritOfStorms
	waitmessage
	delay 100
	closemessage
	delay 40
	fadescreen FADE_TO_BLACK
	applymovement LOCALID_CAMERA, Myth_Movement_PositionCameraToFourthShot
	delay 60
	removeobject LOCALID_MYTH_TORNADUS
	removeobject LOCALID_MYTH_THUNDURUS
	setobjectxyperm LOCALID_MYTH_TORNADUS, 30, 23
	setobjectxyperm LOCALID_MYTH_THUNDURUS, 12, 23
	setobjectmovementtype LOCALID_MYTH_TORNADUS, MOVEMENT_TYPE_WALK_IN_PLACE_LEFT
	setobjectmovementtype LOCALID_MYTH_THUNDURUS, MOVEMENT_TYPE_WALK_IN_PLACE_RIGHT
	addobject LOCALID_MYTH_TORNADUS
	addobject LOCALID_MYTH_THUNDURUS
	addobject LOCALID_MYTH_MAN
	addobject LOCALID_MYTH_MAN2
	addobject LOCALID_MYTH_WOMAN
	setvar VAR_0x8004, 3  @ vertical pan
	setvar VAR_0x8005, 3  @ horizontal pan
	setvar VAR_0x8006, 5  @ num shakes
	setvar VAR_0x8007, 3  @ shake delay
	fadescreen FADE_FROM_BLACK
	delay 25
	message Myth_Text_FightEndlessly
	playmoncry SPECIES_TORNADUS, CRY_MODE_NORMAL
	delay 10
	playmoncry SPECIES_THUNDURUS, CRY_MODE_NORMAL
	waitmoncry
	applymovement LOCALID_MYTH_TORNADUS, Myth_Movement_TornadusFightThundurus1
	applymovement LOCALID_MYTH_THUNDURUS, Myth_Movement_ThundurusFightTornadus1
	waitmovement 0
	playse SE_BANG
	special ShakeCamera
	applymovement LOCALID_MYTH_TORNADUS, Myth_Movement_TornadusRetreatFromThund1
	applymovement LOCALID_MYTH_THUNDURUS, Myth_Movement_ThundurusRetreatFromTorn1
	delay 140
	applymovement LOCALID_MYTH_TORNADUS, Myth_Movement_TornadusFightThundurus2
	applymovement LOCALID_MYTH_THUNDURUS, Myth_Movement_ThundurusFightTornadus2
	waitmovement 0
	playse SE_BANG
	special ShakeCamera
	applymovement LOCALID_MYTH_TORNADUS, Myth_Movement_TornadusRetreatFromThund2
	applymovement LOCALID_MYTH_THUNDURUS, Myth_Movement_ThundurusRetreatFromTorn2
	delay 100
	closemessage
	playmoncry SPECIES_TORNADUS, CRY_MODE_NORMAL
	delay 10
	playmoncry SPECIES_THUNDURUS, CRY_MODE_NORMAL
	waitmoncry
	delay 60
	fadescreen FADE_TO_BLACK
	applymovement LOCALID_CAMERA, Myth_Movement_PositionCameraToFifthShot
	waitmovement 0
	applymovement LOCALID_CAMERA, Myth_Movement_CameraPanHumansPokemon
	fadescreen FADE_FROM_BLACK
	delay 20
	message Myth_Text_Humans
	playse SE_EXIT
	applymovement LOCALID_MYTH_MAN2, Myth_Movement_Man2HideInCave
	waitmovement 0
	applymovement LOCALID_MYTH_MAN, Myth_Movement_ManHideInCave
	applymovement LOCALID_MYTH_WOMAN, Myth_Movement_WomanHideInCave
	delay 48
	playse SE_EXIT
	delay 16
	playse SE_EXIT
	delay 56
	message Myth_Text_Pokemon
	delay 25
	playmoncry SPECIES_KECLEON, CRY_MODE_NORMAL
	delay 15
	applymovement LOCALID_MYTH_KECLEON, Myth_Movement_KecleonDisappears
	delay 60
	playmoncry SPECIES_BUNNELBY, CRY_MODE_NORMAL
	applymovement LOCALID_MYTH_BUNNELBY_RIGHT, Myth_Movement_BunnelbyRRunToForest
	applymovement LOCALID_MYTH_BUNNELBY_LEFT, Myth_Movement_BunnelbyLRunToForest
	delay 100
	closemessage
	delay 60
	fadescreen FADE_TO_BLACK
	delay 20
	applymovement LOCALID_CAMERA, Myth_Movement_PositionCameraToSixthShot
	delay 65
	clearflag FLAG_HIDE_MYTH_CELEBI
	removeobject LOCALID_MYTH_TORNADUS
	removeobject LOCALID_MYTH_THUNDURUS
	setobjectxyperm LOCALID_MYTH_LANDORUS, 21, 18
	setobjectxyperm LOCALID_MYTH_TORNADUS, 24, 24
	setobjectxyperm LOCALID_MYTH_THUNDURUS, 18, 24
	setobjectxyperm LOCALID_MYTH_CELEBI, 8, 23
	setobjectmovementtype LOCALID_MYTH_TORNADUS, MOVEMENT_TYPE_WALK_IN_PLACE_LEFT
	setobjectmovementtype LOCALID_MYTH_THUNDURUS, MOVEMENT_TYPE_WALK_IN_PLACE_RIGHT
	clearflag FLAG_HIDE_FIRST_PAN
	addobject LOCALID_MYTH_TORNADUS
	addobject LOCALID_MYTH_THUNDURUS
	addobject LOCALID_MYTH_CELEBI
	setvar VAR_0x8004, 3  @ vertical pan
	setvar VAR_0x8005, 3  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 3  @ shake delay
	message Myth_Text_AsIfFromTheHeavens
	waitmessage
	delay 80
	closemessage
	playmoncry SPECIES_LANDORUS, CRY_MODE_NORMAL
	waitmoncry
	delay 50
	fadescreen FADE_FROM_BLACK
	delay 40
	applymovement LOCALID_MYTH_LANDORUS, Myth_Movement_LandorusEnterScene
	waitmovement
	delay 60
	playmoncry SPECIES_LANDORUS, CRY_MODE_NORMAL
	applymovement LOCALID_MYTH_LANDORUS, Myth_Movement_LandorusBeatTorn
	waitmovement 0
	playse SE_SUPER_EFFECTIVE
	special ShakeCamera
	applymovement LOCALID_MYTH_TORNADUS, Myth_Movement_TornadusBeatenByLandorus
	applymovement LOCALID_MYTH_LANDORUS, Myth_Movement_LandorusRetreatFromTorn
	waitmovement 0
	delay 90
	playmoncry SPECIES_LANDORUS, CRY_MODE_NORMAL
	applymovement LOCALID_MYTH_LANDORUS, Myth_Movement_LandorusBeatThund
	waitmovement 0
	playse SE_SUPER_EFFECTIVE
	special ShakeCamera 
	applymovement LOCALID_MYTH_THUNDURUS, Myth_Movement_ThundurusBeatenByLandorus
	applymovement LOCALID_MYTH_LANDORUS, Myth_Movement_LandorusRetreatFromThund
	waitmovement 0
	delay 90
	message Myth_Text_LandorusCameDown
	waitmessage
	delay 100
	closemessage
	fadenewbgm MUS_NONE
	setweather WEATHER_NONE
	doweather
	applymovement LOCALID_MYTH_TORNADUS, Myth_Movement_TornadusFlee
	applymovement LOCALID_MYTH_THUNDURUS, Myth_Movement_ThundurusFlee
	delay 120
	removeobject LOCALID_MYTH_TORNADUS
	removeobject LOCALID_MYTH_THUNDURUS
	setobjectxyperm LOCALID_MYTH_TORNADUS, 0, 0
	setobjectxyperm LOCALID_MYTH_THUNDURUS, 0, 0
	message Myth_Text_WithTheSpiritsQuelled
	applymovement LOCALID_CAMERA, Myth_Movement_PanCameraToCelebi
	delay 60
	applymovement LOCALID_MYTH_CELEBI, Myth_Movement_CelebiEnterScene
	delay 100
	playmoncry SPECIES_CELEBI, CRY_MODE_NORMAL
	waitmoncry
	delay 40
	closemessage
	delay 40
	fadescreen FADE_TO_BLACK
	delay 10
	special RemoveCameraObject
	warpsilent MAP_CUTSCENE_TOWN, 9, 23
	waitstate
	end

@ 14 14 to 14 21
Myth_Movement_PositionCameraToFirstShot:
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	step_end

@14 21 to 26 21
Myth_Movement_CameraPanDiagonalDownSetScene:
	walk_slow_diag_southeast
	walk_slow_diag_southeast
	walk_slow_diag_southeast
	walk_slow_diag_southeast
	walk_slow_diag_southeast
	walk_slow_diag_southeast
	walk_slow_diag_southeast
	walk_slow_diag_southeast
	walk_slow_diag_southeast
	walk_slow_diag_southeast
	walk_slow_diag_southeast
	walk_slow_diag_southeast
	step_end

@26 21 to 31 22
Myth_Movement_PositionCameraToSecondShot:
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	step_end

@31 22 to 31 15
Myth_Movement_CameraPanUpTornadus:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Myth_Movement_FlyInPlace:
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	step_end

@31 15 to 16 21
Myth_Movement_PositionCameraToThirdShot:
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	step_end
	
@16 21 to 16 28
Myth_Movement_CameraPanDownThundurus:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

@16 28 to 21 23
Myth_Movement_PositionCameraToFourthShot:
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	step_end

Myth_Movement_TornadusFightThundurus1:
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	step_end

Myth_Movement_TornadusRetreatFromThund1:
	face_up
	lock_facing_direction
	walk_down
	walk_down
	walk_down
	delay_16
	delay_16
	delay_16
	unlock_facing_direction
	step_end

Myth_Movement_TornadusFightThundurus2:
	walk_faster_up
	walk_faster_up
	walk_faster_up
	step_end

Myth_Movement_TornadusRetreatFromThund2:
	face_right
	lock_facing_direction
	walk_left
	walk_left
	walk_left
	unlock_facing_direction
	step_end

Myth_Movement_ThundurusFightTornadus1:
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	step_end

Myth_Movement_ThundurusRetreatFromTorn1:
	face_down
	lock_facing_direction
	walk_up
	walk_up
	walk_up
	delay_16
	delay_16
	delay_16
	unlock_facing_direction
	step_end

Myth_Movement_ThundurusFightTornadus2:
	walk_faster_down
	walk_faster_down
	walk_faster_down
	step_end

Myth_Movement_ThundurusRetreatFromTorn2:
	face_left
	lock_facing_direction
	walk_right
	walk_right
	walk_right
	unlock_facing_direction
	step_end

@21 23 to 9 5
Myth_Movement_PositionCameraToFifthShot:
	@walk_faster_up
	@walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	step_end

@9 5 to 31 5
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

@31 5 to 21 23
Myth_Movement_PositionCameraToSixthShot:
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	@walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
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
	delay_16
	delay_8
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

Myth_Movement_LandorusBeatThund:
	walk_faster_left
	walk_faster_left
	walk_faster_left
	step_end

Myth_Movement_LandorusRetreatFromThund:
	lock_facing_direction
	walk_right
	walk_right
	walk_right
	unlock_facing_direction
	step_end

Myth_Movement_ThundurusBeatenByLandorus:
	lock_facing_direction
	walk_faster_left
	walk_faster_left
	walk_faster_left
	unlock_facing_direction
	step_end
	
Myth_Movement_LandorusBeatTorn:
	walk_faster_down
	walk_faster_right
	walk_faster_right
	walk_faster_right
	step_end

Myth_Movement_LandorusRetreatFromTorn:
	lock_facing_direction
	walk_left
	walk_left
	walk_left
	unlock_facing_direction
	step_end

Myth_Movement_TornadusBeatenByLandorus:
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
	walk_faster_right
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_left
	walk_faster_down
	walk_faster_down
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
	delay_16
	delay_16
	delay_16
	delay_16
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	step_end

@Pan over an empty forest
Myth_Text_LongAgo:
	.string "Long ago, Porta Bella was but a\n"
	.string "turbulent wasteland on a stormy bay.$"

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
	.string "Landorus came down, and quelled the\n"
	.string "two fighting spirits.$"

@Celebi Enters Shot
Myth_Text_WithTheSpiritsQuelled:
	.string "With the spirits pacified, so too\n"
	.string "appeared Celebi…$"


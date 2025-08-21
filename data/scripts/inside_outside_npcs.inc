Common_EventScript_MoveOutsideNPCsInside::
    setflag FLAG_HIDE_OUTSIDE_NPCS
    clearflag FLAG_HIDE_INSIDE_OUTSIDE_NPCS
    return
    
Common_EventScript_MoveInsideNPCsOutside::
    clearflag FLAG_HIDE_OUTSIDE_NPCS
    setflag FLAG_HIDE_INSIDE_OUTSIDE_NPCS
    setflag FLAG_HIDE_TORNADUS_NPCS
    return

InsideOutside_EventScript_GentlemanInside::
    setvar VAR_TEMP_1, LOCALID_INSIDE_GENTLEMAN
    goto InsideOutside_EventScript_Gentleman
    end

InsideOutside_EventScript_GentlemanOutside::
    setvar VAR_TEMP_1, LOCALID_OUTSIDE_GENTLEMAN
    goto InsideOutside_EventScript_Gentleman
    end

InsideOutside_EventScript_AngryManInside::
    setvar VAR_TEMP_1, LOCALID_INSIDE_ANGRY_MAN
    goto InsideOutside_EventScript_AngryMan
    end

InsideOutside_EventScript_AngryManOutside::
    setvar VAR_TEMP_1, LOCALID_OUTSIDE_ANGRY_MAN
    goto InsideOutside_EventScript_AngryMan
    end

InsideOutside_EventScript_LeafInside::
    setvar VAR_TEMP_1, LOCALID_INSIDE_LEAF
    goto InsideOutside_EventScript_Leaf
    end

InsideOutside_EventScript_LeafOutside::
    setvar VAR_TEMP_1, LOCALID_OUTSIDE_LEAF
    goto InsideOutside_EventScript_Leaf
    end

InsideOutside_EventScript_Leaf:
    end
    
InsideOutside_EventScript_Gentleman::
    lock
    faceplayer
    call Script_GetNPCFacingDirection
    speak VAR_TEMP_1, VAR_0x8005, Name_Gentleman, InsideOutside_Text_GentlemanNiceHavingMoney
    speak LOCALID_PLAYER, VAR_FACING, Name_Looker, InsideOutside_Text_LookerTextIndeedItIs
    speak VAR_TEMP_1, VAR_0x8005, Name_Gentleman, InsideOutside_Text_GentlemanIndeed
    closemessage
    applymovement VAR_TEMP_1, Common_Movement_FaceOriginalDirection
    waitmovement 0
    release
    end

InsideOutside_EventScript_AngryMan::
    lock
    faceplayer
    goto_if_set FLAG_SPOKE_TO_ANGRY_MAN_POST_AQUACORP, InsideOutside_EventScript_CalmMan
    call Script_GetNPCFacingDirection
    speak VAR_TEMP_1, VAR_0x8005, Name_Angry_Man, InsideOutside_Text_AngryManAngry
    checkspecies SPECIES_GOREBYSS
    goto_if_eq VAR_RESULT, TRUE, InsideOutside_EventScript_AngryManActually
    checkspecies SPECIES_HUNTAIL
    goto_if_eq VAR_RESULT, TRUE, InsideOutside_EventScript_AngryManActually
    returnqueststate QUEST_INTERROGATE_MATT
    goto_if_eq VAR_RESULT, 4, InsideOutside_EventScript_LookerDots
    speak LOCALID_PLAYER, VAR_FACING, Name_Looker, InsideOutside_Text_LookerTroubling
    closemessage
    release
    end

InsideOutside_EventScript_LookerDots::
    speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_Dots
    closemessage
    release
    end

InsideOutside_EventScript_AngryManActually::
    speak LOCALID_PLAYER, VAR_FACING, Name_Looker, InsideOutside_Text_LookerActuallyChowder
    closemessage
    playse SE_PIN
    applymovement VAR_TEMP_1, Common_Movement_ExclamationMark
    waitmovement 0
    delay 50
    speak VAR_TEMP_1, VAR_0x8005, Name_Angry_Man, InsideOutside_Text_AngryManReally
    closemessage
    setflag FLAG_SPOKE_TO_ANGRY_MAN_POST_AQUACORP
    release
    end
    
InsideOutside_EventScript_CalmMan::
    speakername Name_Calm_Man
    msgbox InsideOutside_Text_AngryManCuteName, MSGBOX_DEFAULT
    closemessage
    release
    end
    
InsideOutside_Text_GentlemanNiceHavingMoney:
    .string "Oh ho ho!\p"
    .string "Isn't it wonderful being an adult?\p"
    .string "Unlike those silly children, we have\n"
    .string "the money to heal our Pokémon\l"
    .string "whenever we want!\p"
    .string "Sir, don't you think that's nice?$"

InsideOutside_Text_LookerTextIndeedItIs:
    .string "Indeed it is.$"

InsideOutside_Text_GentlemanIndeed:
    .string "Oh ho ho!\n"
    .string "Indeed!$"

InsideOutside_Text_AngryManAngry:
    .string "This is outrageous!\p"
    .string "Team Aqua is menacing our wildlife!\p"
    .string "Have you heard? They're even turning\n"
    .string "the local Clamperl into Clamperl\l"
    .string "Chowder! How despicable!$"

InsideOutside_Text_LookerTroubling:
    .string "That is rather troubling…$"

InsideOutside_Text_LookerActuallyChowder:
    .string "Actually, Chowder was the name of\n"
    .string "one of the Clamperl they studied.\p"
    .string "They figured out how to evolve the\n"
    .string "Pokémon in captivity.\p"
    .string "In fact, he's with me now.$"

InsideOutside_Text_AngryManReally:
    .string "Really?\p"
    .string "The Clamperl Chowder was actually\n"
    .string "the Clamperl, Chowder?\p"
    .string "Well I'll be…$"

InsideOutside_Text_AngryManCuteName:
    .string "… … …\n"
    .string "… … …\p"
    .string "… … …\n"
    .string "… … …\p"
    .string "Chowder's kind of a cute name…$"
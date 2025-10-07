Route106_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route106_OnTransition
	.byte 0

Route106_OnTransition:
	call_if_ne VAR_BRINEY_LOCATION, 4, Route106_Hide_Briney
	call_if_eq VAR_BRINEY_LOCATION, 4, Route106_Show_Briney
	end

Route106_Hide_Briney::
	setflag FLAG_HIDE_ROUTE_106_MR_BRINEY
	setflag FLAG_HIDE_ROUTE_106_MR_BRINEY_BOAT
	end

Route106_Show_Briney::
    clearflag FLAG_HIDE_ROUTE_106_MR_BRINEY
    clearflag FLAG_HIDE_ROUTE_106_MR_BRINEY_BOAT
    end

Route106_EventScript_TrainerTipsSign::
	msgbox Route106_Text_TrainerTips, MSGBOX_SIGN
	end

Route106_EventScript_Douglas::
	trainerbattle_single TRAINER_DOUGLAS, Route106_Text_DouglasIntro, Route106_Text_DouglasDefeated
	msgbox Route106_Text_DouglasPostBattle, MSGBOX_AUTOCLOSE
	end

Route106_EventScript_Kyla::
	trainerbattle_single TRAINER_KYLA, Route106_Text_KylaIntro, Route106_Text_KylaDefeated
	msgbox Route106_Text_KylaPostBattle, MSGBOX_AUTOCLOSE
	end

Route106_EventScript_Elliot::
	trainerbattle_single TRAINER_ELLIOT_1, Route106_Text_ElliotIntro, Route106_Text_ElliotDefeated, Route106_EventScript_ElliotRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route106_EventScript_ElliotRematch
	msgbox Route106_Text_ElliotPostBattle, MSGBOX_DEFAULT
	release
	end

Route106_EventScript_ElliotRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route106_Text_ElliotRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ELLIOT_1
	release
	end

Route106_EventScript_ElliotRematch::
	trainerbattle_rematch TRAINER_ELLIOT_1, Route106_Text_ElliotRematchIntro, Route106_Text_ElliotRematchDefeated
	msgbox Route106_Text_ElliotRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route106_EventScript_Ned::
	trainerbattle_single TRAINER_NED, Route106_Text_NedIntro, Route106_Text_NedDefeated
	msgbox Route106_Text_NedPostBattle, MSGBOX_AUTOCLOSE
	end

Route106_Text_TrainerTips:
	.string "Trainer Tips\p"
	.string "Advice on catching Pokémon with a Rod:\n"
	.string "Press the A Button if you get a bite.$"

Route106_EventScript_LittlerootWoodsSign::
	msgbox Route106_Text_LittlerootWoodsSign, MSGBOX_SIGN
	end

Route106_Text_LittlerootWoodsSign:
	.string "North to Littleroot Woods.\n"
	.string "A charming forest, home to many Pokémon.$"

Route106_EventScript_Briney::
	lock
    faceplayer
    message Route106_Text_BackToDewford
    waitmessage
    multichoicedefault 21, 6, MULTI_YESNO, 2, FALSE
    switch VAR_RESULT
    case 0, Route106_EventScript_Yes
    case 2, Route106_EventScript_CancelSailSelect
    case MULTI_B_PRESSED, Route106_EventScript_CancelSailSelect
    end

Route106_Text_BackToDewford:
	.string "Mr. Briney: So you want to be heading\n"
	.string "back to Dewford Town?$"

Route106_EventScript_Yes::
	msgbox Route106_Text_Briney_DewfordSettingSail, MSGBOX_DEFAULT
	closemessage
	goto Route106_EventScript_SailToDewford
	release
	end

Route106_Text_Briney_DewfordSettingSail:
    .string "Mr. Briney: Aye aye!\n"
    .string "We're setting sail for Dewford!$"

Route106_EventScript_SailToDewford::
	releaseall
	end

Route106_EventScript_CancelSailSelect::
	msgbox Route106_Text_JustTellMeWhenYouNeedToSetSail, MSGBOX_DEFAULT
	closemessage
	release
	end

Route106_Text_JustTellMeWhenYouNeedToSetSail:
	.string "Mr. Briney: You just tell me whenever\n"
	.string "you need to set sail again!$"


// Npc: /d/gaochang/npc/ghost.c

inherit NPC;


void create()
{
	set_name("孤魂野鬼", ({
		"gui",
		"phost",
	}));
	set("long",
		"他看起来若有若无，缥缈不定。一身有说不出的诡异.\n"
		"你看到他心头生起寒意。\n"
	);

	set("gender", "男性");
	set("attitude", "aggressive");
	set("class", "bonze");
	set("no_get", 1);
	set("age", 100);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 500);
	set("max_jing", 300);
	set("neili", 500);
	set("max_neili", 500);
	set("pursuer", 1);
	set("combat_exp", 2000);
	set("score", 1);

	set_skill("force", 30);
	set_skill("dodge", 30);
	set_skill("unarmed", 30);
	set_skill("parry", 30);



	setup();

//	carry_object(__DIR__"obj/jiedao")->wield();
//	carry_object(__DIR__"obj/cloth")->wield();
}


void init()
{
	object ob = this_player();
	
	::init();
if (ob)
{
if (userp(ob))
{
	if (interactive(ob))
	{
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob); 
	}       
}
}
}


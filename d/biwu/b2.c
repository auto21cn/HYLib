inherit ROOM;
void create()
{
	set("short", "����¥�ڶ���");
	set("long", @LONG
����һ�������˽�����ʮ�����ɸ��ֵ�¥������ʮ��֮�ߡ�
LONG );
       set("no_sleep_room",1);
       set("no_clean_up", 0);
	set("exits", ([
		"down" : __DIR__"b1",
		"up":__DIR__"b3",
	]));
		set("objects", ([
			__DIR__"chen": 1,
		]));
setup();
}

void init()
{
add_action("do_dazuo","dazuo");
add_action("do_dazuo","exercise");
add_action("do_dazuo","steal");
add_action("do_dazuo","beg");
add_action("do_dazuo","fight");
add_action("do_dazuo","ansuan");
add_action("do_dazuo","hit");
add_action("do_dazuo","get");
}

int do_dazuo()
{
   object me;
   me = this_player();
   tell_object(me,"���ﲻ�������ָ�\n");
return 1;
}
int valid_leave(object me, string dir)
{
        object ob;
if( userp(me) &&
dir=="up" && ob=present("chen jinnan", this_object()))
return notify_fail( 
"����Ӳ������\n");
return 1;
}


#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"��֮����"NOR);
	set("long", HIY @LONG
  ���ڻ�Ԫ�ص�Ӱ�죬�⸽��ȫ��ɰĮ��������֮����������
��ɰĮ�����ϵ�һ������!!����������������������˵������
����һƬ��
LONG NOR);
set("magicroom",1);
set("magicset",1);
set("no_fight",1);
	set("exits", ([
		"south" : __DIR__"dong22",
                "north" : __DIR__"dong31",
	]));
         set("objects", ([
              __DIR__"npc/lev2" : random(2),
         ]));

	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
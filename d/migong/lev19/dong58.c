
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", RED"��֮��"NOR);
	set("long",HIW @LONG
   ��������һ��������ɽ�������һƬ�տ�������ֻ�б�������պ���
���еİ��ƾ����������������ĺ���������˷����������������Щ���䡣
�������������磿��������в��ɵ���������  
LONG NOR);

set("magicroom",1);set("outdoors","migong");
set("magicset",1);

	set("exits", ([
		"west" : __DIR__"dong59",
		"east" : __DIR__"dong5"+(random(5)+4),
		"south" : __DIR__"dong5"+(random(5)+4),
		"north" : __DIR__"dong5"+(random(5)+4),
	]));
if (random(2)==0)
	set("exits", ([
		"west" : __DIR__"dong5"+(random(5)+3),
		"east" : __DIR__"dong5"+(random(5)+4),
		"south" : __DIR__"dong59",
		"north" : __DIR__"dong5"+(random(5)+1),
	]));
        set("objects", ([
              __DIR__"npc/lev6" : 6,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

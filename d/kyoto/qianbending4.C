// Room: d/kyoto/qianbending4
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "ǧ���");
set("long", @LONG
�������ǧ����ᴩ���������Ĵ�����Ҳ������Ľ���������
�йݵ����۴��αȡ�������һ�����ֺŵ���ʳ�㣬���۸�����ʳ��������
һ�䵱�̣����Ե䵱������Ʒ��

LONG );
set("exits",  ([
        "north"  : __DIR__"dangpu",
        "south"  : __DIR__"mianshidian",
        "west"  : __DIR__"shangyuan2",
        "east"  : __DIR__"qianbending5",
      ]));
        setup();
        replace_program(ROOM);
}
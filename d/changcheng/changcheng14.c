// Room: /d/wizhome/incahome/changcheng14.c
// Date: inca 98/08/13

#include <ansi.h>
inherit ROOM;

void create()
{

        set("short",WHT "����");
        set("long", WHT @LONG
���ڳ����ܵ���ɳ����ʴ��һС�γ�ǽ�Ѿ���������ֻ����ʱ���Աߵ�
С·�ƹ�ȥ������������Կ�������Ȼ�еĵط��Ѿ�������������������Ȼ
��ΰ��������ɽ�����������������ȥ��
LONG
NOR        );

        set("outdoors", "changcheng");

        set("exits", ([
                "west"          :__DIR__"changcheng15",
                "southeast"     :__DIR__"FengHuoTai2-1",
        ]));

        setup();
        replace_program(ROOM);
}

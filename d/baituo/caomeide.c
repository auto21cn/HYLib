//ROOM caomeide.c
inherit ROOM;
void create()
{
        set("short","��ݮ��");
        set("long",
             "������һ���ݮ�أ��ʺ�Ĳ�ݮɢ�����̲��У����˸е�������⡣\n"
        );
        set("exits", ([
                "northeast" : __DIR__"shulin1",
                "west" : "/quest/menpaijob/baituo/shechang",
        ]));
        set("objects" , ([
             __DIR__"obj/caomei" : random(7),
        ]));
//        set("no_clean_up", 0);
        set("outdoors","baituo");
    set_temp("wayao1",2);
        setup();
        replace_program(ROOM);
}
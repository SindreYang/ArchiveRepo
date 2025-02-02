# -*- coding: UTF-8 -*-
'''
=================================================
@path   ：dzkd_invoice -> 测试扫描仪
@IDE    ：CLion
@Author ：sindre
@Date   ：2020/4/10 下午2:03
==================================================
'''
__author__ = 'sindre'
import pyinsane2

pyinsane2.init()
try:
    devices = pyinsane2.get_devices()
    assert(len(devices) > 0)
    device = devices[0]
    print("我将使用以下扫描仪：％s" % (str(device)))

    try:
        pyinsane2.set_scanner_opt(device, 'source', ['ADF', 'Feeder'])
    except Exception:
       print("找不到扫描仪")

    # Beware: Some scanners have "Lineart" or "Gray" as default mode
    # better set the mode everytime
    pyinsane2.set_scanner_opt(device, 'mode', ['Color'])

    # Beware: by default, some scanners only scan part of the area
    # they could scan.
    pyinsane2.maximize_scan_area(device)

    scan_session = device.scan(multiple=True)
    try:
        while True:
            try:
                scan_session.scan.read()
            except EOFError:
                print ("有一页！: %d)"
                       % (len(scan_session.images)))
    except StopIteration:
        print("扫描. Got %d pages"
              % len(scan_session.images))
    for idx in range(0, len(scan_session.images)):
        image = scan_session.images[idx]
finally:
    pyinsane2.exit()

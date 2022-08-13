t = """10-2.fdf, 10-70.fdf, 100-6.fdf, 20-60.fdf, 42.fdf, 50-4.fdf, basictest.fdf,
elem-col.fdf, elem-fract.fdf, elem.fdf, elem2.fdf, julia.fdf,
mars.fdf, n_lines, pentenegpos.fdf, plat.fdf, pnp_flat.fdf, pylone.fdf,
pyra.fdf, pyramide.fdf, t1.fdf, t2.fdf"""

files = t.split(", ")
print "#!/bin/bash"
for i in files:
    print "./fdf test_maps/"+ i.strip(); print "echo" "\"" + i + "\""

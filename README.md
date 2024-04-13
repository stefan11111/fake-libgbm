Valve strikes again with needless dependencies.
The sequel of https://github.com/stefan11111/fake-libudev

At least this one is more excusable.
I, at least, find it more reasonable for a game launcher to depend on a graphics library as opposed to a /dev manager, like last time.
Well, that dep isn't gone either, instead it's hidden steam's runtime.

I am using nvidia's proprietary drivers, at the open source drivers don't work with hwaccel.
As such, I am using nvidia's implementation of everything in mesa, including libgbm.
On my setup, and similar setups libgbm does nothing, and is just an extra dependency of steam.
I would have just patched steam if I could, but I can't do that since steam is proprietary.

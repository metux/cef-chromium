This repo holds specific snapshots of Chromium plus extra patches,
for building CEF. It's not meant for generic Chromium builds.

Since the original history is so insanely massive (millions of commits
and files), and pushing shallow clones to github doens't work, we have
artificially cut the history and only import specific baselines needed
by CEF.

The branches named as "cef_"+<chromium-tag> starting off with the
latest commit of the corresponding chromium tag, followed by extra
commits needed for CEF.

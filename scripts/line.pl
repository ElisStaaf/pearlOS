#!/usr/bin/perl

if (@ARGV < 1) {
	print STDERR "usage: line file:address[,address] ...\n" .
		"\taddress is n or /regexp/[+-n]\n";
	exit 1;
}

sub num($) {
	my ($i) = @_;
	return substr($lines[$i], 0, 4);
}

sub line($$) {
	my ($p, $i) = @_;
	my $delta = 0;
	if($p =~ /^\d+$/) {
		return $p - 1;
	}
	if($p =~ /(.*?)([+-]\d+)$/) {
		$p = $1;
		$delta = $2;
	}
	if($p !~ /^\/(.*)\/$/) {
		print STDERR "invalid address: $p\n";
		exit 1;
	}
	$p = $1;
	for(; $i<@strip; $i++) {
		if($strip[$i] =~ $p) {
			return $i + $delta;
		}
	}
	print STDERR "no match for $p\n";
	exit 1;
}

sub find($) {
	my $arg = $_[0];
	$arg =~ s/!/\\/g;
	if($arg !~ /^(.*?):(.*)$/) {
		print STDERR "invaid file:address: ", $_[0];
		exit 1;
	}

	my ($file, $pattern) = ($1, $2);
	
	open(F, "../xv6/fmt/$file") || die "open ../xv6/fmt/$file: $!";
	@lines = <F>;
	close F;
	
	@strip = @lines;
	s/^[0-9]{4} // for @strip;

	if ($pattern =~ /(.*?),(.*)/) {
		($p1, $p2) = ($1, $2);
		my $i = line($p1, 0);
		my $j = line($p2, $i+1);
		return sprintf num($i) . "-" . num($j);
	} else {
		my $i = line($pattern, 0);
		return num($i);
	}
}

for($i=0; $i<@ARGV; $i++) {
	my $s = $ARGV[$i];
	if($s =~ /:/) {
		push @all, find($s);
	} else {
		push @all, $s;
	}
}

printf ".ds LINE \"%s\n", join(', ', @all);